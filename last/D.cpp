#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int gcd(int a, int b) {
    int minimum = std::min(a, b);
    int maximum = std::max(a, b);
    while (minimum * maximum != 0) {
        maximum = maximum % minimum;
        std::swap(minimum, maximum);
    }
    return maximum + minimum;
}

vector<long long> v;
long long m, n;
long long answer = -1;

void process_variant(vector<int> &b) {
    long long cur_ans = 0;

    for (long long i = 0; i < n; ++i)
        cur_ans += v[i] * b[i];
    if (cur_ans == m)
        answer = m;

    int i = n - 1;
    while ((i >= 0) && (b[i] == 2)) {
        b[i] = 0;
        --i;
    }

    if (i!=-1) {
        ++b[i];
        process_variant(b);
    }

}

int main() {
    ios::sync_with_stdio(false);
    string nl = "\n";
    cin >> m >> n;
    vector<int> b(n, 0);
    v.resize(n);
    for (long long i = 0; i < n; ++i)
        cin >> v[i];

    process_variant(b);
    if (answer == m) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
