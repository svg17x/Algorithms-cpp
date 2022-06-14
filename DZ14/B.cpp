#include <iostream>
#include <vector>

using namespace std;

void process_variant(vector<bool> &b, int n, vector<bool> &best, int &best_answer, vector<vector<vector<long>>> &v) {
    int current_answer = 0;
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < v[i].size(); ++j) {
            int neigh = v[i][j][0];
            int val = v[i][j][1];
            if (b[i] != b[neigh]) {
                current_answer += val;
            }
        }
    }

    if (current_answer > best_answer) {
        best_answer = current_answer;
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
        process_variant(b, n, best, best_answer, v);
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
    int answer = 0;
    process_variant(b, n, best, answer, v);
    cout << answer / 2 << '\n';
    for (int i = 0 ; i < n; ++i)
        cout << 1 + static_cast<int>(best[i]) << ' ';
    return 0;
}
