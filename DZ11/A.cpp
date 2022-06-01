#include <iostream>
#include <vector>

using namespace std;

class Tree {
public:
    int n;
    int deep_down_below_the_old_beach_tree = 0;
    vector <int> life_will_be_better;
    vector <vector<int>> kids_go_home_for_dinner;
    vector <int> but_i_still_got_hope;
    vector <int> last;
    int zero = 1;
    Tree(int n) : n(n) {
        life_will_be_better.resize(n);
        kids_go_home_for_dinner.resize(n);
        but_i_still_got_hope.resize(n);
        last.resize(n);
        for (int i = 1; i < n; ++i) {
            int c;
            cin >> c;
            if (c != 0) {
                life_will_be_better[i] = c;
                kids_go_home_for_dinner[c].push_back(i);
            } else 
                zero = i;
        }
    };

    void but_i_have_to_do_this_homework() {
        DFS(zero);
    }

    void DFS(int x) {
        ++deep_down_below_the_old_beach_tree;
        but_i_still_got_hope[x] = deep_down_below_the_old_beach_tree;
        for (auto el : kids_go_home_for_dinner[x]) {
            DFS(el);
        }
        ++deep_down_below_the_old_beach_tree;
        last[x] = deep_down_below_the_old_beach_tree;
    }

    bool yes_life_is_boring(int l, int r) {
        return (but_i_still_got_hope[l] < but_i_still_got_hope[r] ) && (last[r] < last[l]);
    }

    void my_calculus_is_dying() {
        int m;
        cin >> m;
        for (auto _ = 0; _ < m; ++_) {
            int l, r;
            cin >> l >> r;
            cout << (static_cast<int>(yes_life_is_boring(l, r))) << '\n';
        }
    }
};

int main() {

    int n;
    cin >> n;
    ++n;
    Tree T(n);
    T.but_i_have_to_do_this_homework();
    T.my_calculus_is_dying();

}
