//
// Created by PC on 2025/10/21.
//


#include <algorithm>
#include <ctime>
#include <random>
#include <stack>

template<typename T>
class SkipList {
    class Node {
        friend class SkipList;
    public:
        Node(int key, T val): key_(key), val_(std::move(val)) {}
        const int& get_key() const {
            return key_;
        }
        const T& get_val() const {
            return val_;
        }
    private:
        int key_;
        T val_;
        Node* right{};
        Node* down{};
    };
public:
    static constexpr int kMaxLevel = 8;

    SkipList(): head_(new Node(INT_MIN, {})), u_(0,1), height_() {
        dfe_.seed(time(nullptr));
    }

    const T& Find(int key, const T& default_val) {
        auto node = Find(key);
        return node ? node->val_ : default_val;
    }

    void Remove(int key) {
        auto *n = head_;
        while (n) {
            if (!n->right) {
                n = n->down;
            } else if (n->right->key_ == key) {
                auto *to_delete = n->right;
                n->right = n->right->right;
                delete to_delete;
                n = n->down;
            } else if (n->right->key_ > key) {
                n = n->down;
            } else {
                n = n->right;
            }
        }
    }

private:
    Node* head_;
    std::default_random_engine dfe_;
    std::uniform_int_distribution<> u_;
    int height_;

    Node* Find(int key) {
        auto* n = head_;
        while (n) {
            if (n->key_ == key) {
                break;
            }
            if (!n->right || n->right->key_ > key) {
                n = n->down;
            } else {
                n = n->right;
            }
        }
        return n;
    }

    void Add(int key, const T& val) {
        if (auto* existed = Find(key)) {
            existed->val_ = val;
            return;
        }
        std::stack<Node*> st;
        auto* team = head_;
        while (team) {
            if (!team->right || team->right->key_ > key) {
                st.push(team);
                team = team->down;
            } else {
                team = team->right;
            }
        }
        int lv = 1;
        Node* downNode = nullptr;
        while (!st.empty()) {
            team = st.top();
            st.pop();
            auto* nodeTeam = new Node(key, val);
            nodeTeam->down = downNode;
            downNode = nodeTeam;
            if (team->right) {
                nodeTeam->right = team->right;
                team->right = nodeTeam;
            } else {
                team->right = nodeTeam;
            }
            if (lv > kMaxLevel || u_(dfe_)) {
                break;
            }
            lv++;
            if (lv > height_) {
                height_ = lv;
                auto* new_head = new Node(INT_MIN, {});
                new_head->down = head_;
                head_ = new_head;
                st.push(new_head);
            }
        }
    }
};
