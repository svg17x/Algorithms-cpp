#include <iostream>
#include <map>
#include <set>
#include <algorithm>


using namespace std;
#define long long long

void remember_dividor(long x, map<long, long> &v, set<long> &s) {
    s.insert(x);
    ++v[x];
}

int main() {
    std::ios::sync_with_stdio(false);
    long alcohol_in_the_night, Vc_in_morning;
    cin >> alcohol_in_the_night >> Vc_in_morning;

    set<long> shot_tequila;
    map<long ,long> virtual_not_that_one;
    {
        while (Vc_in_morning % 2 == 0) {
            remember_dividor(2, virtual_not_that_one, shot_tequila);
            Vc_in_morning /= 2;
        }
        long  i = 2;
        long x = i * 2 - 1;
        while ((Vc_in_morning != 1) && (Vc_in_morning >= x * x)) {
            x = i * 2 - 1;
            while (Vc_in_morning % x == 0) {
                remember_dividor(x, virtual_not_that_one, shot_tequila);
                Vc_in_morning /= x;
            }
            ++i;
        }
        if (Vc_in_morning > 1) {
            remember_dividor(Vc_in_morning, virtual_not_that_one, shot_tequila);
        }
    }

    long ans = 1000000000;
    for (long el : shot_tequila) {
        long cur = 0;
        long cur_el = el;
        while (alcohol_in_the_night / cur_el > 0) {
            cur += alcohol_in_the_night / cur_el;
            cur_el *= el;
        }
        ans = min(ans, cur / virtual_not_that_one[el]);
    }
    cout << ans;
}
