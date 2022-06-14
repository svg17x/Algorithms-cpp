#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int gcd(int a, int b) {
    int minim = std::min(a, b);
    int maxim = std::max(a, b);
    while (minim * maxim != 0) {
        maxim = maxim % minim;
        std::swap(minim, maxim);
    }
    return maxim + minim;
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
