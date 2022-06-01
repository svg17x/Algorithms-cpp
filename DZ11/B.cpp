#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Tree {
public:
    int n;
    int m;
    int count = -1;
    int count_first = -1;
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> who_are_the_champg;
    vector<int> who_is_stupid_yuxinnnn;
    vector<int> order;
    vector<int> champgn_but_in_a_poliadak;
    vector<int> randomly_change_my_code_to_express_my_feeling;
    vector<int> no_thing_important;
    int zero = 0;
    vector<vector<int>> up;

    Tree(int n) : n(n) {
        cin >> m;
        parent.resize(n);
        children.resize(n);
        who_are_the_champg.resize(n);
        who_is_stupid_yuxinnnn.resize(n);
        no_thing_important.resize(n + 1);
        champgn_but_in_a_poliadak.resize(n + 1);/*
        randomly_change_my_code_to_express_my_feeling.resize(n);*/
        order.resize(2 * n + 2);
        up.resize(n, vector<int>(ceil(log2(n) + 1)));
        for (int i = 1; i < n; ++i) {
            int c;
            cin >> c;
            parent[i] = c;
            children[c].push_back(i);
        }
    };

    void Process() {
        DFS(zero);
    }

    void DFS(int x, int prev = 0) {
        ++count;
        ++count_first;
        who_are_the_champg[x] = count;
        order[count_first] = x;
        no_thing_important[count_first] = x;
        champgn_but_in_a_poliadak[x] = count_first;
        up[x][0] = prev;
        for (int i = 1; i <= ceil(log2(n)); ++i) {
            up[x][i] = up[up[x][i - 1]][i - 1];
        }

        for (auto el : children[x]) {
            DFS(el, x);
        }
        ++count;
        who_is_stupid_yuxinnnn[x] = count;
    }

    bool is_ancestor(int l, int r) {
        return (who_are_the_champg[l] <= who_are_the_champg[r]) && (who_is_stupid_yuxinnnn[r] <= who_is_stupid_yuxinnnn[l]);
    }

    int i_dont_care_bout_my_design(int f, int s) {
        if (is_ancestor(f, s)) return f;
        else if (is_ancestor(s, f)) return s;
        else {
            for (int deg = ceil(log2(n)); deg > -1; --deg) {
                if (!is_ancestor(up[f][deg], s)) {
                    f = up[f][deg];
                }
            }
            return up[f][0];
        }

    }

    void linear_algebra_is_my_life() {
        long long fortune_no_long_lifeline = 0;
        long long babe, plz_Go_aside;
        long long a1, a2;
        cin >> babe >> plz_Go_aside;
        long long x, y, z;
        cin >> x >> y >> z;
        a1 = babe;
        a2 = plz_Go_aside;
        long long nothing_can_be_real_excite = 0;
        for (auto i = 0; i < m; ++i) {

            nothing_can_be_real_excite = i_dont_care_bout_my_design((a1 + nothing_can_be_real_excite) % n, a2);
            a1 = (a1 * x + y * a2 + z) % n;
            a2 = (a2 * x + y * a1 + z) % n;
            fortune_no_long_lifeline += nothing_can_be_real_excite;
        }
        cout << fortune_no_long_lifeline;
    }
};


int main() {
    int n;
    cin >> n;
    Tree T(n);
    T.Process();
    T.linear_algebra_is_my_life();
}
