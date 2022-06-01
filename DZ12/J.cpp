#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define long long long
//好多龙
int main() {
    std::ios::sync_with_stdio(false);
    long first_input;
    cin >> first_input;
    vector<long> i_got_my_stamina;
    for (long j = 0; j < 2 * first_input; ++j) {
        long c;
        cin >> c;
        i_got_my_stamina.push_back(c);

    }
    sort(i_got_my_stamina.begin(), i_got_my_stamina.end());
    if (first_input == 1) {
        cout << i_got_my_stamina[0] << ' ' << 0;
    } else {
        bool fl = true;
        while (fl) {
            long a = rand() % (2*first_input);
            long b = rand() % (2*first_input);
            if (a == b) {
                continue;
            }
            a = i_got_my_stamina[a];
            b = i_got_my_stamina[b];
            long diff = a - b;
            if (diff == 0) {
                if (upper_bound(i_got_my_stamina.begin(), i_got_my_stamina.end(), a)- lower_bound(i_got_my_stamina.begin(), i_got_my_stamina.end(), a) >= first_input) {
                    cout << a << ' ' <<  0;
                    return 0;
                }
            } else {
                for (long j = 1; j * j <= diff; ++j) {
                    if (diff % j == 0) {
                        long d = j;
                        long count = 0;
                        long max_len = abs(i_got_my_stamina[0] - i_got_my_stamina.back()) / d;
                        if (max_len >= first_input - 1) {
                            long cur_a = a;
                            ++count;
                            while (binary_search(i_got_my_stamina.begin(), i_got_my_stamina.end(), cur_a - d)) {
                                cur_a -=d;
                                ++count;
                            }
                            long least = cur_a;
                            cur_a = a;
                            while (binary_search(i_got_my_stamina.begin(), i_got_my_stamina.end(), cur_a + d)) {
                                cur_a +=d;
                                ++count;
                            }
                            if (count >= first_input) {
                                cout << least << ' ' << d;
                                fl = false;
                                break;
                            }

                        }
                        d = diff / j;
                        count = 0;
                        max_len = abs(i_got_my_stamina[0] - i_got_my_stamina.back()) / d;
                        if (max_len >= first_input - 1) {
                            long cur_a = a;
                            ++count;
                            while (binary_search(i_got_my_stamina.begin(), i_got_my_stamina.end(), cur_a - d)) {
                                cur_a -=d;
                                ++count;
                            }
                            long least = cur_a;
                            cur_a = a;
                            while (binary_search(i_got_my_stamina.begin(), i_got_my_stamina.end(), cur_a + d)) {
                                cur_a +=d;
                                ++count;
                            }
                            if (count >= first_input) {
                                cout << least << ' ' << d;
                                fl = false;
                                break;
                                //当你美丽的束缚发可以区分不同顺序的大括号的时候，世界就变得美好了起来，耶耶耶耶耶耶耶
                                //life is beautiful
                                //明年我要卷死大家啊啊啊啊啊啊啊啊！！！！！
                                //暑假开卷！
                                //actually i got different color in my ide ofr each of {}
                            }//color pink
                        }//yellow
                    }//blue
                }//pink
            }//yellow

        }//blue

    }//pink
}//yellow