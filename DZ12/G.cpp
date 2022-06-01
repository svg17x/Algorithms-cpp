#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void print(long long x, map<long long, long long> & v, set<long long> & s) {
    s.insert(x);
    ++v[x];
}

int main() {
    std::ios::sync_with_stdio(false);
    set<long long> s;
    map<long long, long long> v;
    long long n;
    cin >> n;
    // long long n_ = n;
    while (n % 2 == 0) {
        print(2, v, s);
        n /= 2;
    }
    long long i = 2;
    long long x = i * 2 - 1;
    while ((n != 1) && (n >= x * x)) {
        x = i * 2 - 1;
        while (n % x == 0) {
            print(x, v, s);
            n /= x;
        }
        ++i;
    }
    if (n > 1) {
        print(n, v, s);
    }
    long long shot = 1;
    // long long power = 0;
    map<long long, long long> v_multip;
    for (long long el : s) {
        shot *= el;
        v_multip[el] = 1;
    }

    for (long long el : s) {
        while (v_multip[el] * shot < v[el]) {
            shot *= el;
            ++v_multip[el];
        }
    }
    cout << shot;
}