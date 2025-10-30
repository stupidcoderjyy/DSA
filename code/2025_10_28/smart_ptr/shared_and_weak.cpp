//
// Created by PC on 2025/10/30.
//

#include <iostream>
#include <memory>

struct NodeB;

struct NodeA {
    std::shared_ptr<NodeB> node_b;
    ~NodeA() {
        std::cout << "~NodeA\n";
    }
};

struct NodeB {
    std::weak_ptr<NodeA> node_a;
    ~NodeB() {
        std::cout << "~NodeB\n";
    }
};

int main() {
    {
        auto pa = std::make_shared<NodeA>();
        auto pb = std::make_shared<NodeB>();
        pa->node_b = pb;
        pb->node_a = pa;
        std::cout << pb->node_a.expired() << '\n';
    }

    try {
        auto pc = std::make_shared<NodeA>();
        throw std::runtime_error("");
    } catch (std::runtime_error&) {
    }
    return 0;
}