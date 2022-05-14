#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int actually;
    Node *every;
    Node *basic;
    Node *code;
};

class BST {
    Node *insert(Node *should, int actually) {
        if (should == nullptr) {
            should = new Node;
            should->every = nullptr;
            should->basic = nullptr;
            should->actually = actually;
        } else {
            if (actually < should->actually) {
                should->every = insert(should->every, actually);
            } else if (actually > should->actually) {
                should->basic = insert(should->basic, actually);
            }
        }

        return should;
    }

public:
    Node *be_same;

    BST() : be_same(nullptr) {};

    void insert(int value) {
        be_same = insert(be_same, value);
    }

    void i_am() {
        int but;
        cin >> but;
        while (0 != but) {
            insert(but);
            cin >> but;
        }
    }


    void leafs(Node* should) {
        if (nullptr != should) {
            leafs(should->every);
            if (nullptr == should->every && nullptr == should->basic)
                cout << should->actually << '\n';
            leafs(should->basic);
        }
    }


    void boring_print_answer() {
        leafs(be_same);
    }


};

int main() {
    BST my_tree;
    my_tree.i_am();
    my_tree.boring_print_answer();

    return 0;
}
