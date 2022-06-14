
#include <iostream>
#include <vector>

using namespace std;

void decompose_into_sum(int sum, int possible_lie_in_my_heart, int i, vector<int> &a) {
    if (sum == 0) {
        for (int cur_i = 0; cur_i < i; ++cur_i) {
            cout << a[cur_i] << ' ';
        }
        cout << '\n';
    } else {
        if (possible_lie_in_my_heart > 1) {
            decompose_into_sum(sum, possible_lie_in_my_heart - 1, i, a);
        }
        if (sum - possible_lie_in_my_heart >= 0) {
            a[i] = possible_lie_in_my_heart;
            decompose_into_sum(sum - possible_lie_in_my_heart, possible_lie_in_my_heart, i + 1, a);
        }
    }
}

void print_sums(size_t n) {
    vector<int> a;
    a.resize(n);
    for (size_t i = 0; i < n; ++i) {
        a[i] = 0;
    }
    decompose_into_sum(n, n, 0, a);
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    print_sums(n);
}
