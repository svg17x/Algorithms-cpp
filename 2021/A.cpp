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

int main() {
    ios::sync_with_stdio(false);
    string nl = "\n";
    int a, b, c, d;
    cin >> a  >> b >> c >> d;
    int m = a*d + b * c;
    int n = d * b;
    cout << m / gcd(n,m) << ' ' << n / gcd(n,m);



    return 0;
}
