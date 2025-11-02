//
// Created by PC on 2025/11/2.
//

#ifndef DSA_THREADPOOL_H
#define DSA_THREADPOOL_H
#include <deque>
#include <functional>
#include <future>
#include <thread>

class ThreadPool {
    typedef std::function<void()> Task;
public:
    explicit ThreadPool(uint32_t thread_count);
    ThreadPool(const ThreadPool& other) = delete;
    ThreadPool(ThreadPool&& other) = delete;
    ~ThreadPool();

    bool Start();
    void Stop();

    template<typename F, typename ... Args>
    void Enqueue(F&& f, Args&& ... args);

    template<typename F, typename ... Args>
    auto EnqueueReturnable(F&& f, Args&& ... args) -> std::future<std::result_of_t<F(Args...)>>;
private:
    void AddThread();
    std::deque<Task> tasks_;
    std::vector<std::thread> threads_;
    std::atomic<uint32_t> thread_count_;
    std::atomic<bool> open_;
    std::mutex mutex_;
    std::condition_variable cv_;
};

template<typename F, typename ... Args>
void ThreadPool::Enqueue(F &&f, Args &&...args) {
    if (!open_.load()) {
        throw std::runtime_error("not available");
    }
    auto func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    std::lock_guard lock(mutex_);
    tasks_.emplace_back([func] {
        func();
    });
    cv_.notify_one();
}

template<typename F, typename ... Args>
auto ThreadPool::EnqueueReturnable(F &&f, Args &&...args) -> std::future<std::result_of_t<F(Args...)>> {
    if (!open_.load()) {
        throw std::runtime_error("not open");
    }
    using return_t = std::result_of_t<F(Args...)>;
    auto p_task = std::make_shared<std::packaged_task<return_t()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    std::lock_guard lock(mutex_);
    tasks_.emplace_back([p_task] {
        (*p_task)();
    });
    cv_.notify_one();
    return std::move(p_task->get_future());
}

#endif //DSA_THREADPOOL_H
