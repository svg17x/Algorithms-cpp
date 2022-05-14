#include <iostream>

#include <algorithm>
#include <vector>
// #include <fstream>
#include <limits>
#include <set>
#include <queue>

using namespace std;

class Graph {
public:
    int num_towns, num_roads, num_cities;
    priority_queue<pair<int, int>> nodes;
    int capital;
    set<pair<int, int>> answer;
    vector<vector<pair<int, int>>> graph;
    vector<bool> visited;
    vector<long> dist;
    vector<int> cities;
    Graph(int n, int m, int c) : num_towns(n), num_cities(m), capital(c - 1) {
        cities.resize(num_cities);
        graph.resize(num_towns);
        visited.resize(num_towns);
        dist.resize(num_towns, numeric_limits<int>::max());
    }
    void dijkstra() {
        dist[capital] = 0;
        nodes.push({0, capital});
        while (!nodes.empty()) {
            auto now = nodes.top();
            nodes.pop();
            int temp_index = now.second;
            /*for (auto x : nodes) {
                        cout << x << ' ';
                    }
                    cout << '\n';*/
            for (auto neighbour : graph[temp_index]) {
                visited[temp_index] = true;
                if (dist[temp_index] + neighbour.second < dist[neighbour.first]) {
                    dist[neighbour.first] = dist[temp_index] + neighbour.second;
                    nodes.push({-dist[neighbour.first], neighbour.first});
                }
            }
        }

        for (int city: cities) {
            if (city != 0) {
                // cout << city - 1 << '\n';
                answer.insert({dist[city - 1], city});
            /*for (auto x : cities) {
                        cout << x << ' ';
                    }
                    cout << '\n';*/
            /*for (auto x : dist) {
                        cout << x << ' ';
                    }
                    cout << '\n';*/
            }
        }
    }
};


int main() {
    // fstream input("input.txt");
    int num_towns, num_cities, num_roads, cap, parent, child, weight;
    cin >> num_towns >> num_roads >> num_cities >> cap;
    Graph g(num_towns, num_cities, cap);
    for (int i = 0; i < num_cities; ++i) {
        // cin >> g.cities[i];
        cin >> g.cities[i];
    }
    for (int i = 0; i < num_roads; ++i) {
        // cin >> parent >> child >> weight;
        cin >> parent >> child >> weight;
        --parent;
        --child;
        if (parent != child) {
            g.graph[parent].push_back({child, weight});
            g.graph[child].push_back({parent, weight});
        }
    }
    g.dijkstra();
    for (auto pair : g.answer) {
        cout << pair.second << ' ' << pair.first << '\n';
    }
}
