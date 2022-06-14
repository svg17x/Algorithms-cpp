
#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    long long minimum = min(a, b);
    long long maximum = max(a, b);
    while (minimum * maximum != 0) {
        maximum = maximum % minimum;
        swap(minimum, maximum);
    }
    return maximum + minimum;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    v.resize(1 + n);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    vector<bool> considered(1 + n, false);
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        int cur = i;
        long long i_will_achive_anything = 1;
        while (v[cur] != i) {
            cur = v[cur];
            ++i_will_achive_anything;
        }
        ans = ans * i_will_achive_anything / gcd(ans, i_will_achive_anything);
    }
    cout << ans;
    return 0;
}