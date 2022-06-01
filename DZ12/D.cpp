#include <iostream>
#include <vector>

using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    long n, m;
    cin >> n >> m;
    vector<bool> a;
    a.resize(m + 1, true);
    for (int i = 2; i * i <= m; ++i) {
        if (a[i]) {
            long start = i * i;
            long addit = i;
            if (i != 2) {
                addit += addit;
            }
            while (start <= m) {
                a[start] = false;
                start += addit;
            }
        }
    }
    bool sth_was_printed = false;
    for (int i = n ; i <= m ; ++i) {
        if (a[i]) {
            cout << i << '\n';
            sth_was_printed = true;
        }
    }
    if (!sth_was_printed) {
        cout << "Absent";
    }
}
