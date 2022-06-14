#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    string nl = "\n";

    long long n, k;
    cin >> n >> k;
    long long answer = 0;
    long long l = 0;
    long long r = 0;
    vector<long long> v;
    v.resize(n, 0);
    for (long long i = 0; i < n; ++i)
        cin >> v[i];
    long long sum = v[0];
    for (long long i = 0; i < n; ++i) {
        while (sum < k && r < n - 1) {
            ++r;
            sum += v[r];
        }
        while (sum > k and l < n - 1) {
            sum -= v[l];
            ++l;
        }
        if (sum == k) {
            ++answer;
            ++l;
            sum -=v[l -1];
        }

        if (r == n - 1 and sum < k)
            break;
    }

    cout << answer;
    return 0;
}
