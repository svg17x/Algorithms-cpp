#include <iostream>

using namespace std;

void print(long long x) {
    cout << x << ' ';
}

int main() {
    std::ios::sync_with_stdio(false);
    long long fuck_me;
    cin >> fuck_me;
    while (fuck_me % 2 == 0) {
        print(2);
        fuck_me /= 2;
    }
    long long i = 2;
    long long x = i * 2 - 1;
    while ((fuck_me != 1) && (fuck_me >= x * x)) {
        x = i * 2 - 1;
        while (fuck_me % x == 0) {
            print(x);
            fuck_me /= x;
        }
        ++i;
    }
    if (fuck_me > 1) {
        print(fuck_me);
    }
}
