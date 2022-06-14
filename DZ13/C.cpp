#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> v) {
    for (size_t i = 1; i < v.size(); ++i)
        cout << v[i];
    cout << '\n';

    int i = v.size() - 1;
    while (v[i - 1] >= v[i]){
        --i;
    }

    if (i == 1) {
        return;
    } else {
        --i;
        int i_min = i + 1;
        for (size_t cur = i + 1; cur < v.size(); ++cur) {
            if (v[i_min] > v[cur] && v[cur] > v[i]) {
                i_min = cur;
            }
        }
        swap(v[i_min], v[i]);
        reverse(v.begin() + 1 + i, v.end());
        print(v);
    }
}

void print_permutations(size_t n) {
    vector<int> v;
    v.resize(n + 1);
    for (size_t i = 1; i <= n; ++i) {
        v[i] = i;
    }
    print(v);
}


int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    print_permutations(n);
}
