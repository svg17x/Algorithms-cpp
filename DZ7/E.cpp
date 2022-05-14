#include <iostream>
#include <algorithm>

using namespace std;

struct N {
    int k;
    N *l;
    N *r;
    N *p;
};

class BST {
    N *i(N *n, int k) {
        if (n == nullptr) {
            n = new N;
            n->l = nullptr;
            n->r = nullptr;
            n->k = k;
        } else {
            if (k < n->k) {
                n->l = i(n->l, k);
            } else if (k > n->k) {
                n->r = i(n->r, k);
            }
        }

        return n;
    }

public:
    N *ro;

    BST() : ro(nullptr) {};

    void i(int v) {
        ro = i(ro, v);
    }

    void J() {
        int x;
        cin >> x;
        while (0 != x) {
            i(x);
            cin >> x;
        }
    }


    void ye(N* n) {
        if (nullptr != n) {
            ye(n->l);
            if (nullptr != n->l && nullptr != n->r)
                cout << n->k << '\n';
            ye(n->r);
        }
    }


    void P() {
        ye(ro);
    }


};

int main() {
    BST tr;
    tr.J();
    tr.P();

    return 0;
}
