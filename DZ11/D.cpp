#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Tree {
public:
    int inf = 1000001;
    int n;
    int m;
    int count = -1;
    int count_first = -1;
    vector<int> parent;
    vector<vector<vector<int>>> children;
    vector<int> first;
    vector<int> last;
    vector<int> order;
    vector<int> first_in_order;
    vector<int> last_in_order;
    vector<int> why_i_choosed_AMI_because_i_loved_ittt;
    int zero = 0;

    vector<vector<int>> up;
    vector<vector<int>> i_am_a_lazy_butt_buttt;

    Tree(int n) : n(n) {
        //this code is from the last one and some basic ideas are the same so just fuuuuuuu COYYYYYP
        parent.resize(n + 1);
        children.resize(n + 1);
        first.resize(n + 1);
        last.resize(n + 1);
        why_i_choosed_AMI_because_i_loved_ittt.resize(n + 1);
        first_in_order.resize(n + 1);/*
        last_in_order.resize(n);*/
        order.resize(2 * n + 2);
        up.resize(n + 1, vector<int>(ceil(log2(n) + 1)));
        i_am_a_lazy_butt_buttt.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            i_am_a_lazy_butt_buttt[i].resize(ceil(log2(n) + 1), inf);
        }
        for (int i = 2; i <= n; ++i) {
            int c;
            int cost;
            cin >> c >> cost;
            parent[i] = c;
            children[c].push_back({i, cost});
        }
        for (int i = 1; i <= n; ++i) {
            if (parent[i] == 0) {
                zero = i;
            }
        }
    };

    void Process() {
        DFS(zero, inf);
    }

    void DFS(int x, int cost, int prev = 1) {
        ++count;
        ++count_first;
        first[x] = count;
        order[count_first] = x;
        why_i_choosed_AMI_because_i_loved_ittt[count_first] = x;
        first_in_order[x] = count_first;
        up[x][0] = prev;
        i_am_a_lazy_butt_buttt[x][0] = cost;

        for (int i = 1; i <= ceil(log2(n)); ++i) {
            up[x][i] = up[up[x][i - 1]][i - 1];
            i_am_a_lazy_butt_buttt[x][i] = min(i_am_a_lazy_butt_buttt[x][i - 1], i_am_a_lazy_butt_buttt[up[x][i - 1]][i - 1]);
        }

        for (auto el : children[x]) {
            DFS(el[0], el[1], x);
        }
        ++count;
        last[x] = count;
    }

    bool is_ancestor(int l, int r) {
        return (first[l] <= first[r]) && (last[r] <= last[l]);
    }

    int least_common_ancestor(int f, int s) {
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

    int find_minimum(int f, int s) {
        int res = inf;
        for (int deg = ceil(log2(n)); deg > -1; --deg) {
            if (!is_ancestor(up[f][deg], s)) {
                res = min(res, i_am_a_lazy_butt_buttt[f][deg]);
                f = up[f][deg];
            } else if (up[f][deg] == s) {
                res = min(res, i_am_a_lazy_butt_buttt[f][deg]);
                break;
            }
        }
        return res;

    }

    void answer_questions() {
        long long ans = 0;
        cin >> m;

        for (auto i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            int anc = least_common_ancestor(x, y);
            ans = min(find_minimum(x, anc), find_minimum(y, anc));
            cout << ans << '\n';
                    /*cout << "i_am_a_lazy_butt_buttt\n";
        for (auto el : i_am_a_lazy_butt_buttt) {
            for (auto e : el) {
                cout << e << ' ';
            }
            cout << '\n';
        }*/

        }

    }
};


int main() {
    int n;
    cin >> n;
    Tree T(n);
    T.Process();
    T.answer_questions();
}