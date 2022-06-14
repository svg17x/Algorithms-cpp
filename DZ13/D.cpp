
#include <iostream>
#include <vector>

using namespace std;

void print_num(vector<bool> v, size_t someleft, size_t idinnitsaleft) {
    if (someleft == 0) {
        for (int i = 0; i < static_cast<int>(v.size()); ++i) {
            if (v[i])
                cout << i + 1 << ' ';
        }
        cout << '\n';
    } else {

        if (idinnitsaleft > 0) {
            v[v.size() - someleft] = true;
            print_num(v, someleft - 1, idinnitsaleft - 1);
        }
        if (idinnitsaleft < someleft) {
            v[v.size() - someleft] = false;
            print_num(v, someleft - 1, idinnitsaleft);
        }
    }
}

void print_binary(size_t bits_count, size_t idinnitsaleft) {
    vector<bool> v;
    v.resize(bits_count, false);
    print_num(v, bits_count, idinnitsaleft);
}


int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int k;
    cin >> k;
    print_binary(n, k);
}
