#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node *ancestor;
};

class Binary_search_tree {
    Node *insert(Node *node, int key) {
        if (node == nullptr) {
            node = new Node;
            node->left = nullptr;
            node->right = nullptr;
            node->key = key;
        } else {
            if (key < node->key) {
                node->left = insert(node->left, key);
            } else if (key > node->key) {
                node->right = insert(node->right, key);
            }
        }

        return node;
    }

public:
    Node *root;

    Binary_search_tree() : root(nullptr) {};

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


    void leafs(Node* node) {
        if (nullptr != node) {
            leafs(node->left);
            if (1 == static_cast<int>(nullptr != node->right) + static_cast<int>(nullptr != node->left))
                cout << node->key << '\n';
            leafs(node->right);
        }
    }


    void PrintAns() {
        leafs(root);
    }


};

int main() {
    Binary_search_tree my_tree;
    my_tree.Process();
    my_tree.PrintAns();

    return 0;
}
//what is the meaning of my life?
//好无聊
//痛定思痛
//不给别人抄答案了操
//现在每一份作业都有一份作业凉凉