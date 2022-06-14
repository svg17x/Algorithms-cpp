#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Task {
public:
    int try_as_my_very_best, m;
    int four_ugolnik;
    vector<int> may_the_force_be_with_u;
    vector<int> jumps_made;
    vector<int> last_holes_within_sector;
    vector<int> leads;
    char nl = '\n';
    char s = ' ';


    Task() {
        cin >> try_as_my_very_best >> m;

        leads.resize(try_as_my_very_best + 1, 0);
        jumps_made.resize(try_as_my_very_best + 1, 0);
        may_the_force_be_with_u.resize(try_as_my_very_best + 1, 0);
        last_holes_within_sector.resize(try_as_my_very_best + 1);
        four_ugolnik = ceil(sqrt(try_as_my_very_best));


        for (int i = 1; i <= try_as_my_very_best; ++i)
            cin >> may_the_force_be_with_u[i];

        for (int i = try_as_my_very_best; i > 0; --i)
            Renew(i, i + may_the_force_be_with_u[i]);


        for (int _ = 0; _ < m; ++_) {
            int i_mean_i_dont_need_anyone_understand_my_homework;
            cin >> i_mean_i_dont_need_anyone_understand_my_homework;
            if (i_mean_i_dont_need_anyone_understand_my_homework == 0) {
                int a, b;
                cin >> a >> b;
                may_the_force_be_with_u[a] = b;
                for (int i = a; (i >= 1) and (a / four_ugolnik - i / four_ugolnik == 0) ; --i) {
                    Renew(i, i + may_the_force_be_with_u[i]);
                }
            } else {
                int rabbit_hole;
                cin >> rabbit_hole;
                Print_Answer(rabbit_hole);
            }
        }
    }


    void Print_Answer(int little_under_number) {
        int number;
        int ans;
        ans = jumps_made[little_under_number];
        number = last_holes_within_sector[little_under_number];
        while (leads[little_under_number] <= try_as_my_very_best) {
            little_under_number = leads[little_under_number];
            number = last_holes_within_sector[little_under_number];
            ans = jumps_made[little_under_number] + ans;
        }
        cout << number << s;
        cout << ans << nl;
    }

    void Renew(int from, int to) {
        if (to > try_as_my_very_best) {
            last_holes_within_sector[from] = from;
            jumps_made[from] = 1;
            leads[from] = try_as_my_very_best + 1002;
            // 结了呗
        } else {
            if (from / four_ugolnik -  to / four_ugolnik == 0) {
            // 这就继续整就完事了
                last_holes_within_sector[from] = last_holes_within_sector[to];
                jumps_made[from] = 1 + jumps_made[to];
                leads[from] = leads[to];
                // 同一个东西
            } else {
                last_holes_within_sector[from] = from;
                jumps_made[from] = 1;
                leads[from] = to;
                // 不一样的咯
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    auto t = Task();
    //每次看到auto我都想到奥迪啊捏马
    return 0;
    //奔驰不贵吗..
}
