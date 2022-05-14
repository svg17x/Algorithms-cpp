#include <iostream>

#include <algorithm>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

class Graph {
public:
    int num_towns, departure;

    priority_queue<pair<int, int>> nodes;
    vector<vector<vector<int>>> graph;
    vector<bool> visited;
    vector<long> times;
    Graph(int n, int m) : num_towns(n), departure(m){
        graph.resize(num_towns + 1);
        visited.resize(num_towns + 1);
        times.resize(num_towns + 1, numeric_limits<int>::max());
    }
    void add_edge(int parent, int time1, int child, int time2) {
        graph[parent].push_back({time1, child, time2});
    }
    void dijkstra() {
        times[departure] = 0;
        nodes.push({0, departure});
        while (!nodes.empty()) {
            pair<int, int> now = nodes.top();
            nodes.pop();
            for (vector<int> child : graph[now.second]) {
                if (-now.first <= child[0]) {
                    visited[now.second] = true;
                    if (child[2] < times[child[1]]) {
                        nodes.push({-child[2], child[1]});
                        times[child[1]] = child[2];
                    }
                }
            }
        }
    }
};


int main() {
    int num_towns, source, destination, num_bus, start_city, start_time, end_city, end_time;
    cin >> num_towns >> source >> destination >> num_bus;
    Graph g(num_towns, source);
    for (int i = 0; i < num_bus; ++i) {
        cin >> start_city >> start_time >> end_city >> end_time;
        g.add_edge(start_city, start_time, end_city, end_time);
                        // cout << now << ' ' << child[0] << '\n';

    }
    g.dijkstra();
    int answer = g.times[destination];
    /*for (auto x : times) {
                        cout << x << ' ';
                    }
                    cout << '\n';*/
    (answer != numeric_limits<int>::max()) ? cout << answer << '\n' : cout << -1 << '\n';
}
