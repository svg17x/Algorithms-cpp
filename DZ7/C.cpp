#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int key_is_not_important_it_is_impossible;
    Node *left;
    Node *right;
    Node *anananananana;
};

class BST {
    Node *insert(Node *node, int key_is_not_important_it_is_impossible) {
        if (node == nullptr) {
            node = new Node;
            node->left = nullptr;
            node->right = nullptr;
            node->key_is_not_important_it_is_impossible = key_is_not_important_it_is_impossible;
        } else {
            if (key_is_not_important_it_is_impossible < node->key_is_not_important_it_is_impossible) {
                node->left = insert(node->left, key_is_not_important_it_is_impossible);
            } else if (key_is_not_important_it_is_impossible > node->key_is_not_important_it_is_impossible) {
                node->right = insert(node->right, key_is_not_important_it_is_impossible);
            }
        }

        return node;
    }

public:
    Node *why_root_there_is_a_reason;

    BST() : why_root_there_is_a_reason(nullptr) {};

    void insert(int value) {
        why_root_there_is_a_reason = insert(why_root_there_is_a_reason, value);
    }

    void Process() {
        int x;
        cin >> x;
        while (0 != x) {
            insert(x);
            cin >> x;
        }
    }


    void ordering(Node* node) {
        if (nullptr != node) {
            ordering(node->left);
            cout << node->key_is_not_important_it_is_impossible << '\n';
            ordering(node->right);
        }
    }


    void PrintAns() {
        ordering(why_root_there_is_a_reason);
    }


};

int main() {
    BST my_tree;
    my_tree.Process();
    my_tree.PrintAns();

    return 0;
}