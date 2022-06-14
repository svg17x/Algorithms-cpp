#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long long> fact;
    fact.push_back(1);
    long long n;

    cin >> n;

    long long k;
    cin >> k;
    for (long long i = 1; i < n; ++i) {
        fact.push_back(fact.back() * i);
    }
    vector<bool> i_dont_have_motivations;
    long long ans = 0;
    long long num_not_used = n;
    i_dont_have_motivations.resize(n + 1, false);
    for (long long i = 0; i < k; ++i) {
        long long cur_ans = 0;
        long long elem;
        cin >> elem;
        for (long long j = 1; j < elem; ++j) {
            if (!i_dont_have_motivations[j])
                ++cur_ans;
        }
        i_dont_have_motivations[elem] = true;
        --num_not_used;
        long long multiplier = 1;
        for (long long j = 0; j < k - (n - num_not_used); ++j) {
            multiplier *= num_not_used - j;
        }
        ans += cur_ans * multiplier;
    }

    cout << ans + 1;
    return 0;
}
