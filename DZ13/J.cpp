
//boring_af_so_that_nobody_can_understand_my_code_imean_metoo
//you_can_only_understand_the_philosophy_meaning
//sorry i shouldnt change that much,u stupid computer
#include <iostream>
#include <vector>

using namespace std;

void process_variant(vector<bool> &b, int n, vector<bool> &best, int &bertter_man, vector<vector<vector<long>>> &v) {
    int boyfriend = 0;
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < v[i].size(); ++j) {
            int neigh = v[i][j][0];
            int val = v[i][j][1];
            if (b[i] != b[neigh]) {
                boyfriend += val;
            }
        }
    }

    if (boyfriend > bertter_man) {
        bertter_man = boyfriend;
        for (int i = 0; i < n; ++i) {
            best[i] = b[i];
        }
    }

    int i = n - 1;
    while ((i >= 0) && (b[i])) {
        b[i] = false;
        --i;
    }

    if (i!=-1) {
        b[i] = true;
        process_variant(b, n, best, bertter_man, v);
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<vector<long>>> v;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long val;
            cin >> val;
            if (val != 0)
                v[i].push_back({j, val});
        }
    }

    vector<bool> b(n, false);
    b[0] = true;
    vector<bool> best(n, false);
    int i_have_abetter_plan = 0;
    process_variant(b, n, best, i_have_abetter_plan, v);
    cout << i_have_abetter_plan / 2 << '\n';
    for (int i = 0 ; i < n; ++i)
        cout << 1 + static_cast<int>(best[i]) << ' ';
    return 0;
}