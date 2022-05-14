#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <limits>
#include <set>
#include <vector>

using namespace std;

struct Coord {
    int weight;
    int ind;
    Coord(int x_, int y_) : weight(x_), ind(y_) {
    }
    Coord() {}
    bool friend operator>(const Coord c1, const Coord c2) {
        return tie(c1.weight, c1.ind) > tie(c2.weight, c2.ind);
    }
};

class Graph {
public:
    int vertices = 0;
    int mst_weight = 0;
    vector<vector<Coord>> graph;
    vector<int> visited;
    vector<int> dist;
    vector<Coord> parents;
    Graph(int n) : vertices(n) {
        graph.resize(vertices + 1);
        visited.resize(vertices + 1);
        parents.resize(vertices + 1, {-1, -1});
        dist.resize(vertices + 1, numeric_limits<int>::max());
    }
    void add_edge(int parent, int child, int weight) {
        graph[parent].push_back({weight, child});
        graph[child].push_back({weight, parent});
    }
    void prim() {
        Coord temp;
        temp.weight = 0;
        temp.ind = 1;
        priority_queue<Coord, vector<Coord>, greater<Coord>> buff;
        buff.push(temp);
        dist[1] = 0;
        while (!buff.empty()) {
            Coord now = buff.top();
            buff.pop();
            if (!visited[now.ind]) {
                mst_weight += now.weight;
                visited[now.ind] = true;
            }
            for (auto child : graph[now.ind]) {
                if (!visited[child.ind]) {
                    buff.push(child);
                }
            }
        }
    }

};


int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    Graph g(vertices);
    int parent, child, weight;
    for (int i = 0; i < edges; ++i) {
        cin >> parent >> child >> weight;
        g.add_edge(parent, child, weight);
    }
    g.prim();
    cout << g.mst_weight << '\n';
}
