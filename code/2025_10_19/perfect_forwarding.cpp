//
// Created by PC on 2025/10/21.
//

#include <iostream>
#include <utility>

template<class T, typename ... Args>
T* MyNew(Args&& ... args) {
    return new T(std::forward<Args>(args)...);
}

class A {
public:
    explicit A(std::string data): data_(std::move(data)) {}
private:
    std::string data_;
};

class Obj {
public:
    explicit Obj(const A& a) {
        std::cout << "Obj(const A& a)" << std::endl;
    }
    explicit Obj(A&& a) {
        std::cout << "Obj(A&& a)" << std::endl;
    }
};

/*
    对于 func(T):
    1) 传入类型为A的左值，编译器会展开为 func(A&)
    2) 传入类型为A的右值，编译器会展开为 func(A)

    引用折叠:
    1) A&&& = A&
    2) A&&&& = A&&

    std::move(T)的工作过程:
    1) 移除T的引用
    2) 加上&&
*/
int main() {
    A l("a");
    //A左值 -new→ Obj(const A& a)
    delete MyNew<Obj>(l);
    //A右值 -new→ Obj(A&& a)
    delete MyNew<Obj>(A{"a"});

    A&& rr = std::move(l);
    //A&&左值 -new→ Obj(const A& a)
    delete MyNew<Obj>(rr);
    //A&&左值 -move→ A&&右值 -new→ Obj(A&& a)
    delete MyNew<Obj>(std::move(rr));

    //A&左值 -new→ Obj(const A& a)
    auto& cr = l;
    delete MyNew<Obj>(cr);
    //A&左值 -move→ A&& 右值 -new→ Obj(A&& a)
    delete MyNew<Obj>(std::move(cr));
}