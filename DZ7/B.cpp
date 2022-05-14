#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int klyuch;
    Node *l;
    Node *r;
    Node *ancesters;
};

class Binary_Search_tree {
    Node *insert(Node *node, int klyuch) {
        if (node == nullptr) {
            node = new Node;
            node->l = nullptr;
            node->r = nullptr;
            node->klyuch = klyuch;
        } else {
            if (klyuch < node->klyuch) {
                node->l = insert(node->l, klyuch);
            } else if (klyuch > node->klyuch) {
                node->r = insert(node->r, klyuch);
            }
        }

        return node;
    }

public:
    Node *root;

    Binary_Search_tree() : root(nullptr) {};

    void insert(int value) {
        root = insert(root, value);
    }

    void Process() {
        int x;
        cin >> x;
        while (0 != x) {
            insert(x);
            cin >> x;
        }
    }

    int depth(Node *node) {
        if (nullptr == node) {
            return 0;
        }
        return max(depth(node->l), depth(node->r)) + 1;
    }

    int get_second_max() {
        Node *node = root;
        Node *prev = root;

        while (node->r != nullptr) {
            prev = node;
            node = node->r;
        }
        if (node->l != nullptr) {
            node = node->l;
            while (node->r != nullptr)
                node = node->r;
            return node->klyuch;
        }
        else
            return prev->klyuch;
    }

    void Answer_be_like() {
        cout << get_second_max();
    }
};

int main() {
    Binary_Search_tree my_tree;
    my_tree.Process();
    my_tree.Answer_be_like();

    return 0;
}
