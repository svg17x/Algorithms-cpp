#include <iostream>
#include <vector>

using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    long pillowtalk_with_polarbear;
    cin >> pillowtalk_with_polarbear;
    if (pillowtalk_with_polarbear % 2 == 0) {
        cout << pillowtalk_with_polarbear / 2 << ' ' << pillowtalk_with_polarbear / 2;
    } else {

        long p = 3;
        while ((pillowtalk_with_polarbear % p != 0) && (p * p <= pillowtalk_with_polarbear)) {
            p += 2;
        }
        if (pillowtalk_with_polarbear % p != 0) {
            cout << 1 << ' ' << pillowtalk_with_polarbear - 1;
        } else {
            cout << pillowtalk_with_polarbear - pillowtalk_with_polarbear / p << ' ' << pillowtalk_with_polarbear / p;
        }
    }
}
//强行给我多了几个留言机会
//但是我其实是不知道啦，为什么为什么
//但世界上没有那么多为什么
//读出来一个文凭就摆烂就完事了
