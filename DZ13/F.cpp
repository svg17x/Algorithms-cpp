#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long long> do_you_really_know_longlong;
    do_you_really_know_longlong.push_back(1);
    long long n;
    long long n_;
    cin >> n;
    n_ = n;
    long long k;
    cin >> k;
    for (long long i = 1; i < n; ++i) {
        do_you_really_know_longlong.push_back(do_you_really_know_longlong.back() * i);
    }
    vector<bool> used;
    used.resize(n + 1, false);
    --k;
    while (n > 0) {
        long long else_number_in_my_heart;
        long long but_i_wont_cry = k / do_you_really_know_longlong[n-1];
        k = k % do_you_really_know_longlong[n-1];
        --n;
        for (long long i = 1; i <= n_; ++i) {
            if (!used[i]) {
                --but_i_wont_cry;
                if (but_i_wont_cry == -1) {
                    used[i] = true;
                    else_number_in_my_heart = i;
                    break;

                }
            }
        }
        cout << else_number_in_my_heart << ' ';
    }
    return 0;
}
