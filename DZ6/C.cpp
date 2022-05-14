#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int columns;
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

struct ans {
    int x;
    int y;
    int weight;
    bool friend operator<(const ans e1, const ans e2) {
        return e1.weight < e2.weight;
    }
};
int f(int x, int y) {
    return x * (columns + 1) + y;
}

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
    int rows;
    int columns;
    int cost;
    vector<edge> edges;
    vector<int> x_axis;
    vector<int> y_axis;
    vector<int> ancestors;
    Graph(int r, int c) : rows(r), columns(c) {
        ancestors.resize((columns + 1) * (rows + 2) + 1, -1);
        cost = 0;
    }
    int find(int x) {
        // cout << x <<  ' ' << "size = " << ancestors.size() << '\n';
                    // cout << "from -- > to --> distance \n";
            // cout << x.from << ' ' << x.to << x.dist << '\n';
        if (ancestors[x] < 0 || ancestors[x] == x) return x;
        ancestors[x] = find(ancestors[x]);
        return ancestors[x];
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
    vector<ans> answer;
    void move(int horizontal, int vertical, int weight) {
        for (int i = 1; i < horizontal; ++i) {
            for (int j = 1; j < vertical; ++j) {
                int new_place;
                if (weight == 1) {
                    new_place = f(i + 1, j);
                } else {
                    new_place = f(i, j + 1);
                }
                if (!Union(f(i, j), new_place)) {
                    continue;
                } else {
                    cost += weight;
                    answer.push_back({i, j, weight});
                                // cout << ancestors[x_root] << ' ' << ancestors[y_root] << '\n';
            // cout << temp_x << ' ' << y_root << '\n';
                        // cout << ancestors[y_root] << ' ' << ancestors[x_root] << '\n';
            // cout << temp_y << ' ' << x_root << '\n';
                }
            }
        }
    }
    void solve () {
        move(rows, columns + 1, 1);
        move(rows + 1, columns, 2);
        cout << answer.size() << ' ' << cost << '\n';
        for (auto x : answer) {
            cout << x.x  << ' ' << x.y << ' ' << x.weight << '\n';
                    //  cout << f(i, j) << ' ' << new_place << '\n';
                    /*cout << "horiz =========\n";
                    for (auto x : hor) {
                        cout << x << ' ';
                    }
                    cout << "\n vertical ========\n";
                    for (auto y : vert) {
                        cout << y <<'\n';
                    }*/
        }
    }
};

int main() {
    int rows;
    cin >> rows >> columns;
    Graph g(rows, columns);
    int val;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= columns; ++j) {
            cin >> val;
            if (val == 0) continue;
            int now = f(i, j);
            if (val == 1) {
                g.Union(now, f(i + 1, j));
            } else if (val == 2) {
                g.Union(now, f(i, j + 1));
            } else {
                g.Union(now, f(i + 1, j));
                g.Union(now, f(i, j + 1));
            }
        }
    }
    g.solve();
}
