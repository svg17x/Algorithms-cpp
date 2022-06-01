#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    long long minimum = std::min(a, b);
    long long maximum = std::max(a, b);
    while (minimum * maximum != 0) {
        maximum = maximum % minimum;
        std::swap(minimum, maximum);
    }
    return maximum + minimum;
}

int main() {
    std::ios::sync_with_stdio(false);
    long long parament1, parament2, obras1, obras2;
    cin >> parament1 >> obras2 >> parament2 >> obras1;
    long long dx = abs(parament2 - parament1);
    long long dy = abs (obras1 - obras2);
    long long gcd_ = gcd(dx, dy);
    long long dx_prev= dx;
    dx /= gcd_;
    dy /= gcd_;
    long long ans;
    if (dx != 0) {
        ans = 1 + ((dx_prev) / dx);
    } else {
        ans = abs(obras1 - obras2) + 1;
    }
    cout << ans;
}
//为什么有的时候改个变量名好玩也会有错误答案，我不太理解，我觉得可能是因为字母太小所以涵盖了所有的东西
//我总觉得我敲键盘的声音特别大而且特别重因为我很大压力啊
//actull sawp is a cute thing but i dont really think that i can handle any of them
//and i am really sorry for that i skipped something 
