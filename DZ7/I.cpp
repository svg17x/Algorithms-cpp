#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int num;
    int key;
    int left;
    int right;
    int parent;
    int count_black = 1;
    int color = 0;
    int minim;
    int maxim;
};

class BST {
    int n;
    int root;
    vector<Node> a;
    bool is_correct_BR = true;

    /* int insert(int node, int key) {
        if (a[node].num == 0) {
            a[node].key = key;
        } else {
            if (key < a[node].key) {
                a[node].left = insert(a[node].left, key);
            } else if (key > a[node].key) {
                a[node].right = insert(a[node].right, key);
            }
        }
        return node;
    }*/

public:

    BST() {
        cin >> n;
        if (n != 0) {
            a.resize(n + 1);
            cin >> root;
        }
    };

    /*void insert(int value) {
        root = insert(root, value);
    }*/

    void Process() {
        if (n > 0) {
            for (int i = 0; i < n; ++i) {
                int num, key;
                string left, right, color;
                cin >> num >> key >> left >> right >> color;
                int color_ = static_cast<int>(color == "B");
                int right_;
                if (right != "null") {
                    right_ = stoi(right);
                } else {
                    right_ = 0;
                }
                int left_;
                if (left != "null") {
                    left_ = stoi(left);
                } else {
                    left_ = 0;
                }
                a[num].left = left_;
                a[num].right = right_;
                a[num].key = key;
                a[num].minim = key;
                a[num].maxim = key;
                a[num].color = color_;
                a[left_].parent = num;
                a[right_].parent = num;
            }
            is_correct_BR = (is_correct_BR) && (a[root].color == 1);
        }
    }

    int num_black_on_the_way_to_leafs(int node) {
        if (0 == node) {
            return 1;
        }
        int d_right = num_black_on_the_way_to_leafs(a[node].right);
        int d_left = num_black_on_the_way_to_leafs(a[node].left);
        is_correct_BR = (is_correct_BR) && (d_left == d_right);

        if (a[node].color == 0) {
            int ancestor = a[node].parent;
            // cout << "ancestor " << ancestor <<  '\n';
            is_correct_BR = (is_correct_BR) && ((a[ancestor].color == 1)  (ancestor == 0));
        }

        a[node].minim = min(a[node].minim, a[node].key);
        if (a[node].left != 0)
            a[node].minim = min(a[node].minim, a[a[node].left].minim);
        a[node].maxim = max(a[node].maxim, a[node].key);
        if (a[node].right != 0)
            a[node].maxim = max(a[node].maxim, a[a[node].right].maxim);

        is_correct_BR = (is_correct_BR) &&
                        ((a[node].key < a[a[node].right].minim)  a[node].right == 0) &&
                        ((a[node].key > a[a[node].left].maxim) || a[node].left == 0);
        return d_left + a[node].color;
    }

    void PrintAns() {
        if (n == 0) {
            cout << "YES";
        } else {
            num_black_on_the_way_to_leafs(root);
            is_correct_BR ? cout << "YES" : cout << "NO";
        }

    }
};

int main() {
    BST my_tree;
    my_tree.Process();
    my_tree.PrintAns();
    return 0;
}
