#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool action = true;


void dfs(const vector<vector<int> > &graph, vector<int>& visited, int position, int coloered) {
    if (action) {
        visited[position] = coloered;
        for (int child: graph[position]) {
            if (!visited[child]) {
                dfs(graph, visited, child, 3 - coloered);
            } else if (visited[child] == coloered) {
                action = false;
            }
        }
    }
}

int main() {
    int verx, edge, left, right;
    cin >> verx >> edge;
    vector<vector<int> > graph(verx + 1);
    vector<int> visited(verx + 1);
    for (int i = 1; i <= edge; ++i) {
        cin >> left >> right;
        graph[left].push_back(right);
        graph[right].push_back(left);
    }
    // 不同染色
    int coloered = 1;
    for (int i = 1; i <= verx; ++i) {
        if (visited[i] == 0) {
            dfs(graph, visited, i, coloered);
        }
    }
    string a = "YES";
    string b = "NO";
    if (action) {
        cout << a << '\n';
    } else {
        cout << b << '\n';
    }
}
