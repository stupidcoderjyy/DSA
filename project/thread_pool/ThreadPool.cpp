//
// Created by PC on 2025/11/2.
//

#include "ThreadPool.h"

ThreadPool::ThreadPool(uint32_t thread_count): thread_count_(thread_count), open_(false) {
}

ThreadPool::~ThreadPool() {
    Stop();
}

bool ThreadPool::Start() {
    if (open_.load()) {
        return false;
    }
    open_ = true;
    uint32_t count = thread_count_;
    for (auto i = 0u; i < count; ++i) {
        AddThread();
    }
    return true;
}

void ThreadPool::Stop() {
    if (open_.load()) {
        open_ = false;
        cv_.notify_all();
        for (auto& thread : threads_) {
            if (thread.joinable()) {
                thread.join();
            }
        }
        threads_.clear();
    }
}

void ThreadPool::AddThread() {
    threads_.emplace_back([this] {
        while (true) {
            Task task;
            {
                std::unique_lock lock(mutex_);
                //等待直到线程池关闭或者收到任务通知
                cv_.wait(lock, [this] {
                    return !open_.load() || !tasks_.empty();
                });
                if (!open_.load()) {
                    break;
                }
                task = std::move(tasks_.front());
                tasks_.pop_front();
            }
            task();
        }
    });
}
