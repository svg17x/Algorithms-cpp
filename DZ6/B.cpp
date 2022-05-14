#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>

using namespace std;
int num_edges;
int num_vertices;
struct edge {
    int from;
    int to;
    int dist;
    bool friend operator<(const edge e1, const edge e2) {
        return e1.dist < e2.dist;
    }
};

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

int distance(int x1, int x2, int y1, int y2) {
    int temp_x = abs(x1 - x2);
    int temp_y = abs(y1- y2);
    return temp_x * temp_x + temp_y * temp_y;
}

double distance(int x, int y) {
    return pow(x * x + y * y, 0.5);
}
class Graph {
public:
    vector<int> ancestors;
    vector<int> x_axis;
    vector<int> y_axis;
    vector<edge> edges;
    vector<int> visited;
    vector<int> dist;
    int mst_weight = 0;
    double answer = 0;
    Graph(int n) {
        ancestors.resize(n + 1, -1);
        x_axis.resize(n + 1);
        y_axis.resize(n + 1);
    }
    int find(int x) {
        if (ancestors[x] < 0 || ancestors[x] == x) return x;
        ancestors[x] = find(ancestors[x]);
        return ancestors[x];
    }
    void prim() {
        Coord temp;
        temp.weight = 0;
        temp.ind = 1;
        vector<vector<Coord>> graph;
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
    bool Union(int x, int y) {
        int y_root = find(y);
        int x_root = find(x);
        if (x_root == y_root)
            return false;
        if (ancestors[x_root] > ancestors[y_root]) {
            int temp_x = ancestors[x_root];
            ancestors[x_root] = y;
            ancestors[y_root] += temp_x;
        } else {
            int temp_y = ancestors[y_root];
            ancestors[y_root] = x;
            ancestors[x_root] += temp_y;
        }
        return true;
    }
    void find_all_dists() {
        for (int i = 1; i <= num_vertices; ++i) {
            for(int j = i + 1; j <= num_vertices; ++j) {
                edges.push_back({i, j, distance(x_axis[i], x_axis[j], y_axis[i], y_axis[j])});
            }
        }
        for (auto x : edges) {
        }
        sort(edges.begin(), edges.end());
    }
    void solve() {
        find_all_dists();
        for (auto edge_ : edges) {
            if (Union(edge_.from, edge_.to)) {
                answer += pow(edge_.dist, 0.5);
                // cout << "now answer = " << answer << '\n';
                            // cout << ancestors[x_root] << ' ' << ancestors[y_root] << '\n';
            // cout << temp_x << ' ' << y_root << '\n';
                                // cout << child.ind << ' ' << child.weight << '\n';
            }
        }
    }
};

int main() {
    cin >> num_vertices;
    Graph g(num_vertices);
    int x, y;
    for (int i = 1; i <= num_vertices; ++i) {
        cin >> g.x_axis[i] >> g.y_axis[i];
    }
    cin >> num_edges;
    for (int i = 1; i <= num_edges; ++i) {
        cin >> x >> y;
        g.Union(x, y);
                    // cout << "from -- > to --> distance \n";
            // cout << x.from << ' ' << x.to << x.dist << '\n';
                /*for (auto x : g.x_axis) {
        cout << x << ' ';
    }
    cout << "===========\n";
    for (auto x : g.y_axis) {
        cout << x << ' ';
    }
    cout << "===========\n";*/
	// 
                // cout << ancestors[y_root] << ' ' << ancestors[x_root] << '\n';
            // cout << temp_y << ' ' << x_root << '\n';
                            // cout << "index = " << now.ind << " weight = " << now.weight << '\n';
    }
    g.solve();
    cout << fixed << setprecision(6) << g.answer << '\n';
}
