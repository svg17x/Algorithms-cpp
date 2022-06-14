#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

class Voyager {
public:
    ll how_to_make_homework_easier;
    ll the_most_beautiful_answer_in_this_world = 10000'000'000;
    ll a_normal_cute_constant_in_my_heart = the_most_beautiful_answer_in_this_world;
    vector<vector<ll>> edges;

    Voyager() {
        cin >> how_to_make_homework_easier;
        edges.resize(how_to_make_homework_easier + 1);
        for (int i = 1; i <= how_to_make_homework_easier; ++i) {
            edges[i].resize(how_to_make_homework_easier + 1);
            for (int j = 1; j <= how_to_make_homework_easier; ++j)
                cin >> edges[i][j];
        }
    }

    void solve() {
        generate_permutations();
        if (the_most_beautiful_answer_in_this_world == a_normal_cute_constant_in_my_heart) {
            cout << -1;
        } else {
            cout << the_most_beautiful_answer_in_this_world;
        }
    }

    void process_permutation(vector<int> &v) {
        if (v[1] == 1)
            the_most_beautiful_answer_in_this_world = min(the_most_beautiful_answer_in_this_world, calculate_route(v));
        else 
            return;
        int i = v.size() - 1;
        while (v[i - 1] >= v[i]) {
            --i;
        }

        if (i == 1) {
            return;
        } else {
            --i;
            int i_min = i + 1;
            for (size_t cur = i + 1; cur < v.size(); ++cur) {
                if (v[i_min] > v[cur] && v[cur] > v[i]) {
                    i_min = cur;
                }
            }
            swap(v[i_min], v[i]);
            reverse(v.begin() + 1 + i, v.end());
            process_permutation(v);
        }
    }


    void generate_permutations() {
        vector<int> v;
        v.resize(how_to_make_homework_easier + 1);
        for (ll i = 1; i <= how_to_make_homework_easier; ++i) {
            v[i] = i;
        }
        process_permutation(v);
    }

    ll calculate_route(const vector<int> &v) {
        ll cur_ans = 0;
        for (int i = 1; i < how_to_make_homework_easier; ++i) {
            int cur = v[i];
            int next = v[1 + i];
            if (0 == edges[cur][next]) {
                return a_normal_cute_constant_in_my_heart;
            } else {
                cur_ans += edges[cur][next];
            }
        }
        if (edges[v[how_to_make_homework_easier]][1] == 0 && how_to_make_homework_easier != 1) {
            return a_normal_cute_constant_in_my_heart;
        }
        cur_ans += edges[v[how_to_make_homework_easier]][1];
        return cur_ans;
    }

};


int main() {
    ios::sync_with_stdio(false);

    Voyager voyager;
    voyager.solve();
    return 0;
}