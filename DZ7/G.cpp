
#include <iostream>
#include <algorithm>

using namespace std;

struct niddle {
    int key;
    niddle *l;
    niddle *r;
    niddle *anc;
};

class Binary_search_tree {
    niddle* insert(niddle* node, int key) {
        if (node == nullptr) {
            node = new niddle;
            node->l = nullptr;
            node->r = nullptr;
            node->key = key;
        }
        else {
            if (key < node->key) {
                node->l = insert(node->l, key);
            } else if (key > node->key) {
                node->r = insert(node->r, key);
            }
        }

        return node;
    }

public:
    niddle* root;
    bool is_fine_already_stop_stalking = true;

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

    int depth(niddle* node) {
        if (nullptr == node) {
            return 0;
        }
        int d_right = depth(node->r);
        int d_left = depth(node->l);
        is_fine_already_stop_stalking = (is_fine_already_stop_stalking) && ((d_left - d_right) * (d_left - d_right) <= 1);
        if (!is_fine_already_stop_stalking)
            return -1;
        return max(depth(node->l), depth(node->r)) + 1;
    }

    void ANSWER_is_HERE() {
        depth(root);
        is_fine_already_stop_stalking ? cout << "YES" : cout << "NO";
    }
};

int main() {
    Binary_search_tree my_tree;
    my_tree.Process();
    my_tree.ANSWER_is_HERE();
    return 0;
}
