#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node *ancesters;
};

class Binary_Search_Tree {
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            node = new Node;
            node->left = nullptr;
            node->right = nullptr;
            node->key = key;
        }
        else {
            if (key < node->key) {
                node->left = insert(node->left, key);
            } else if (key > node->key) {
                node->right = insert(node->right, key);
            }
        }

        return node;
    }

public:
    Node* korin;

    Binary_Search_Tree() : korin(nullptr) {};

    void insert(int znachenie) {
        korin = insert(korin, znachenie);
    }

    void In_Process() {
        int x;
        cin >> x;
        while (0 != x) {
            insert(x);
            cin >> x;
        }
    }

    int depth(Node* node) {
        if (nullptr == node) {
            return 0;
        }
        return max(depth(node->left), depth(node->right)) + 1;
    }

    void Answer_be_like() {
        cout << depth(korin);
    }
};

int main() {
    Binary_Search_Tree my_tree;
    my_tree.In_Process();
    my_tree.Answer_be_like();
    return 0;
}
