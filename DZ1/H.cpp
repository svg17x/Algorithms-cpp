#include <iostream>

#include <vector>
#include <list>

using namespace std;

int maze_makes_me_dizzy(vector<vector<char> >& m2, int m, int n, vector<vector<bool> >& visited) {
    int calculate = 1;
    if (visited[m][n]) {
        return 0;
    }
    //如果经过了就直接送走
    visited[m][n] = 1;
    list<pair<int, int> > current_position;
    //记录目前位置
    current_position.push_back({m - 1, n});
    current_position.push_back({m, n - 1});//普通返回值
    current_position.push_back({m, n + 1});
    current_position.push_back({m + 1, n});
    for (auto& pos : current_position) {
        if (pos.first >= 0 && pos.first < m2.size() && pos.second >= 0 && pos.second < m2.size()) {
            if (m2[pos.first][pos.second] == '.' && !visited[pos.first][pos.second]) {
                calculate += maze_makes_me_dizzy(m2, pos.first, pos.second, visited);
            }
        }
    }
    return calculate;
}

int main() {
    int N;
    //迷宫大小
    cin >> N;
    vector<vector<char> > m2(N, vector<char>(N));
    vector<vector<bool> > visited(N, vector<bool>(N, false));
    for (int m = 0; m < N; m++) {
        for (int n = 0; n < N; n++) {
            cin >> m2[m][n];
        }
    }
    int y, x;
    cin >> y >> x;
    //一个循环后把他们减除
    y--;
    x--;
    cout << maze_makes_me_dizzy(m2, y, x, visited); 
}
