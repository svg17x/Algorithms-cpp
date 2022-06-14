
#include <iostream>
#include <vector>
using namespace std;

void print_num(vector<bool> v, size_t there_are_some_right, size_t there_is_some_left) {
    if (there_are_some_right == 0) {
        for (int el : v) {
            cout << el;
        }
        cout << '\n';
    } else {
        if (there_is_some_left < there_are_some_right) {
            v[v.size() - there_are_some_right] = false;
            print_num(v, there_are_some_right - 1, there_is_some_left);
        }
        if (there_is_some_left > 0) {
            v[v.size() - there_are_some_right] = true;
            print_num(v, there_are_some_right - 1, there_is_some_left - 1);
        }
    }
}

void print_something_i_hate(size_t i_dont_wanna_count, size_t there_is_some_left) {
    vector <bool> v;
    v.resize(i_dont_wanna_count, false);
    print_num(v, i_dont_wanna_count, there_is_some_left);
}


int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int k;
    cin >> k;
    print_something_i_hate(n, k);
}
