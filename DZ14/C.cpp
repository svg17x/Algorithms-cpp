#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

class Brackets {
public:
    int the_last_one_and_i_will_go;
    vector<string> v = {"(", "[", ")", "]"};

    Brackets() {
        cin >> the_last_one_and_i_will_go;
        if (the_last_one_and_i_will_go % 2 != 0)
            return;
        vector<char> st;
        generate_sequences_of_brackets("", st, 0, 0);
    }

    void generate_sequences_of_brackets(string s, vector<char> st, int count_open_round, int count_open_square) {

        if (s.length() > 0) {
            int last = s.size() - 1;
            st.push_back(s[last]);
            while ((st.size() > 1) &&
                   ((st.back() == ']' && st[st.size() - 2] == '[') || (st[st.size() - 2] == '(' && st.back() == ')'))) {
                st.pop_back();
                char el = st.back();
                st.pop_back();
                if (el == '[')
                    --count_open_square;
                else
                    --count_open_round;
            }
            if (s.size() > 1) {
                if (s.back() == ']' && s[s.size() - 2] == '(')
                    return;
                if (s.back() == ')' && s[s.size() - 2] == '[')
                    return;
            }
        }
        if (the_last_one_and_i_will_go - s.length() == 0 && st.size() == 0) {
            cout << s << '\n';
        }
        if (static_cast<size_t>(the_last_one_and_i_will_go) > s.length()) {
            for (int i = 0; i < 4; ++i) {
                if (i < 2) {
                    if (count_open_round + count_open_square < the_last_one_and_i_will_go - static_cast<int>(s.length())) {
                        generate_sequences_of_brackets(s + v[i], st,
                                                       count_open_round + static_cast<int> (i == 0),
                                                       count_open_square + static_cast<int> (i == 1));
                    }
                } else {
                    if (i == 2 && count_open_round > 0) {
                        generate_sequences_of_brackets(s + v[i], st,
                                                       count_open_round,
                                                       count_open_square);
                    }
                    if (i == 3 && count_open_square > 0) {
                        generate_sequences_of_brackets(s + v[i], st,
                                                       count_open_round,
                                                       count_open_square);
                    }
                }

            }
        }

    }
};


int main() {
    ios::sync_with_stdio(false);
    Brackets brackets;
    return 0;
}
