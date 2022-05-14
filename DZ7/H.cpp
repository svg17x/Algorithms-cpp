#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int kliuch;
    Node *l;
    Node *r;
    Node *anc;
    int claculate = 1;
};

class  Binary_search_tree {
    Node* insert(Node* node, int kliuch) {
        if (node == nullptr) {
            node = new Node;
            node->l = nullptr;
            node->r = nullptr;
            node->kliuch = kliuch;
        }
        else {
            if (kliuch < node->kliuch) {
                node->l = insert(node->l, kliuch);
            } else if (kliuch > node->kliuch) {
                node->r = insert(node->r, kliuch);
            } else {
                node->claculate = 1 + node->claculate;
            }
        }

        return node;
    }

public:
    Node* root;

     Binary_search_tree() : root(nullptr) {};

    void insert(int mean) {
        root = insert(root, mean);
    }

    void going() {
        int x;
        cin >> x;
        while (0 != x) {
            insert(x);
            cin >> x;
        }
    }

    void ordering(Node* node) {
        if (nullptr != node) {
            ordering(node->l);
            cout << node->kliuch << ' ' << node->claculate << '\n';
            ordering(node->r);
        }
    }

    void ANSWER_finally_is_here_and_i_am_dying() {
        ordering(root);
    }
};

int main() {
     Binary_search_tree my_tree;
    my_tree.going();
    my_tree.ANSWER_finally_is_here_and_i_am_dying();
    return 0;
}
