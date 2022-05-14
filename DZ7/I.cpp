#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int quantity;
    int key;
    int left;
    int right;
    int ancestor;
    int count_black = 1;
    int color = 0;
    int minimal;
    int mximal;
};

class Binary_search_tree {
    int n;
    int root;
    vector<Node> a;
    bool is_correct_BR = true;

public:

    Binary_search_tree() {
        cin >> n;
        if (n != 0) {
            a.resize(n + 1);
            cin >> root;
        }
    };

    void Process() {
        if (n > 0) {
            for (int i = 0; i < n; ++i) {
                int quantity, key;
                string left, right, color;
                cin >> quantity >> key >> left >> right >> color;
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
                a[quantity].left = left_;
                a[quantity].right = right_;
                a[quantity].key = key;
                a[quantity].minimal = key;
                a[quantity].mximal = key;
                a[quantity].color = color_;
                a[left_].ancestor = quantity;
                a[right_].ancestor = quantity;
            }
            is_correct_BR = (is_correct_BR) && (a[root].color == 1);
        }
    }

    int number_kick_back_to_the_leaves(int node) {
        if (0 == node) {
            return 1;
        }
        int d_right = number_kick_back_to_the_leaves(a[node].right);
        int d_left = number_kick_back_to_the_leaves(a[node].left);
        is_correct_BR = (is_correct_BR) && (d_left == d_right);

        if (a[node].color == 0) {
            int ancestor = a[node].ancestor;
            is_correct_BR = (is_correct_BR) && ((a[ancestor].color == 1) (ancestor == 0));
        }

        a[node].minimal = min(a[node].minimal, a[node].key);
        if (a[node].left != 0)
            a[node].minimal = min(a[node].minimal, a[a[node].left].minimal);
        a[node].mximal = max(a[node].mximal, a[node].key);
        if (a[node].right != 0)
            a[node].mximal = max(a[node].mximal, a[a[node].right].mximal);

        is_correct_BR = (is_correct_BR) &&
                        ((a[node].key < a[a[node].right].minimal) a[node].right == 0) &&
                        ((a[node].key > a[a[node].left].mximal) || a[node].left == 0);
        return d_left + a[node].color;
    }

    void PrintAns() {
        if (n == 0) {
            cout << "YES";
        } else {
            number_kick_back_to_the_leaves(root);
            is_correct_BR ? cout << "YES" : cout << "NO";
        }

    }
};

int main() {
    Binary_search_tree my_tree;
    my_tree.Process();
    my_tree.PrintAns();
    return 0;
}
