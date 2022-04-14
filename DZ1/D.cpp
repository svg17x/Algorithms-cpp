#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int redflag, int baba, vector<bool> &visited, vector<int> &mama, vector<vector<int> >& graph,
         int& lifeline, int& death) {
    visited[redflag] = true;
    for (int a_little_boat_in_the_ocean : graph[redflag]) {
        if (a_little_boat_in_the_ocean == baba) continue;
        if (visited[a_little_boat_in_the_ocean]) {
            death = redflag;
            lifeline = a_little_boat_in_the_ocean;
            return true;
        }
        mama[a_little_boat_in_the_ocean] = redflag;
        if (dfs(a_little_boat_in_the_ocean, mama[a_little_boat_in_the_ocean], visited, mama, graph, lifeline, death)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, val;
    cin >> n;
    vector<int> baba(n + 1, -1);
    vector<bool> visited(n + 1);
    int lifeline = -1;
    int death = -1;
    vector<vector<int> > graph(n + 1);
    int edge = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> val;
            if (val) {
                ++edge;
                graph[i].push_back(j);
            }
        }
    }
    for (int node = 0; node < n; ++node) {
        if (!visited[node]) {
            if (dfs(node, baba[node], visited, baba, graph, lifeline, death)) {
                break;
                //找循环啊啊啊啊
            }
        }
    }
    if (lifeline == -1) {
        cout << "NO" << endl;
    } else {
        vector<int> answer;
        answer.push_back(lifeline);
        for (int v = death; v != lifeline; v = baba[v])
            answer.push_back(v);
        answer.push_back(lifeline);
        reverse(answer.begin(), answer.end());
        cout << "YES" << endl;
        cout << answer.size() - 1 << endl;
        for (size_t i = 0; i < answer.size() - 1; ++i) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
}
