#include <iostream>

using namespace std;

void i_am_tired(long long as_you_see, size_t sometime_fucked, size_t n) {
    if (sometime_fucked == 0) {
        for (long long i = n - 1; i >= 0; --i) {
            cout << static_cast<int>((as_you_see & (1 << i)) != 0);
        }
        cout << '\n';
    } else {
        i_am_tired(as_you_see * 2, sometime_fucked - 1, n);
        i_am_tired(as_you_see * 2 + 1, sometime_fucked - 1, n);
    }
}

void i_Dont_wanna_die_out_here(size_t bits_count) {
    i_am_tired(0, bits_count, bits_count);
}


int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    i_Dont_wanna_die_out_here(n);
}
