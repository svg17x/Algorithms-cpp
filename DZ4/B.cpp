#include <iostream>

#include <fstream>
#include <algorithm>
#include <limits>
#include <deque>
#include <vector>

using namespace std;


class Graph {
public:
    int verxx;
    vector<vector<pair<int, int>>> graph;
    int resource;
    int dest;
    Graph(int n, int begin, int end) : verxx(n), resource(begin), dest(end) {
        graph.resize(verxx);
        --dest;
        --resource;
    }
    void add_edge(int parent, int child, int weight) {
        graph[parent].push_back({child, weight});
    }
    void dijsktra() {
        vector<int> dist(verxx, numeric_limits<int>::max());
        dist[resource] = 0;
        vector<bool> visited(verxx);
        deque<int> parents(verxx, -1);
        int try_min_diss = 0;
        int try_min_indexx = resource;
        while (try_min_diss < numeric_limits<int>::max()) {
            int now = try_min_indexx;
            visited[now] = true;
            for (auto child : graph[now]) {
                int node = child.first;
                int node_weight = child.second;
                if (dist[now] + node_weight < dist[node]) {
                    dist[node] = dist[now] + node_weight;
                    parents[node] = now;
                    //it isnt in my blood
                    //sometime i feel like giving up
                    //no medicine is strong enough
                    //someone help me
                    //i am crawling in my skin
                }
            }
            try_min_diss = numeric_limits<int>::max();
            for (int i = 0; i < verxx; ++i) {
                if (!visited[i] && dist[i] < try_min_diss) {
                    try_min_diss = dist[i];
                    try_min_indexx = i;
                }
            }
        }
        vector<int> answer;
        bool same = resource == dest;
        while (dest != -1){
                answer.push_back(dest);
                dest = parents[dest];
        }
        reverse(answer.begin(), answer.end());
        if (answer.size() > 1 || same) {
            for (auto x : answer) {
                cout << x + 1 << ' ';
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
};

int main() {
    int num_vertices, begin, end, weight;
    cin >> num_vertices >> begin >> end;
    Graph g(num_vertices, begin, end);
    for (int i = 0; i < num_vertices; ++i) {
        for (int j = 0; j < num_vertices; ++j) {
            cin >> weight;
            if (weight != -1)
            g.add_edge(i, j, weight);
        /*if (dist[dest] != numeric_limits<int>::max()) {
            for (auto x : parents) {
                if (x != -1)
                cout << x + 1 << ' ';
            }
            cout << resource << '\n';
        } else {
            cout << -1 << '\n';
        }*/
        }
    }
    g.dijsktra();
}