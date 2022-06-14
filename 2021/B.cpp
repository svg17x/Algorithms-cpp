#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s = "0123456789abcdefghijklmnopqrstuvwxyz";
int numone;
int king_of_the_world;


void print(vector<int> &answer) {
    for (auto elementsuknow : answer) {
        cout << s[elementsuknow];
    }
    cout << '\n';

    int i = numone - 1;
    while (i >= 0 and answer[i] == 0) {
        answer[i] = king_of_the_world -1;
        --i;
    }
    if (i < 0)
        return;
    else {
        --answer[i];
        print(answer);
    }
}

int main() {
    std::ios::sync_with_stdio(false);



    cin >> numone;

    cin >> king_of_the_world;

    vector<int> answer(numone, king_of_the_world - 1);
    print(answer);
}
