#include <iostream>
#include <algorithm>

int gcd(int a, int b) {
    int minimum = std::min(a, b);
    int maximum = std::max(a, b);
    while (minimum * maximum != 0) {
        maximum = maximum % minimum;
        std::swap(minimum, maximum);
    }
    return maximum + minimum;
}
//what if my life is just be like that 
// i think it will be good
//i mean really bailan
//just have fun and learn something
//oh god give me a present plzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b);
}
