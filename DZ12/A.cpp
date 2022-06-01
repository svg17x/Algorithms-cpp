
#include <iostream>

using namespace std;

long long ANSWER(int x, int n, int p) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        long long cur = ANSWER(x, n / 2, p);
        return (cur * cur) % p;
    } else
        return (x * ANSWER(x, n - 1, p)) % p;
}

int main() {
    long long x, n, p;
    cin >> x >> n >> p;
    cout << ANSWER(x, n, p);
}
