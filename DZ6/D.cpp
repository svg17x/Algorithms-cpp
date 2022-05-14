#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int columns;
int num_edges;
int num_vertices;

struct edge {
    int from;
    int to;
    int dist;
    int counted;
    edge() {
    }
    edge(int x, int y, int z, int w) {
        from = x;
        to = y;
        dist = z;
        counted = w;
    }
    bool friend operator<(const edge& e1, const edge& e2) {
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

class Graph {
public:
    int vertices;
    int ans1 = 0;
    int temp = 0;
    vector<edge> edges;
    vector<int> x_axis;
    vector<int> y_axis;
    vector<int> ancestors;
    set<int> candidates;
    Graph(int num_schools) : vertices(num_schools) {
        ancestors.resize(vertices + 1, -1);
    }
    int find(int& x, vector<int>& array) {
        // cout << x <<  ' ' << "size = " << ancestors.size() << '\n';
        if (array[x] < 0 || array[x] == x) return x;
        array[x] = find(array[x], array);
        return array[x];
    }
    bool Union(int& x, int& y, vector<int>& array) {
        int y_root = find(y, array);
        int x_root = find(x, array);
        if (x_root == y_root)
            return false;
        if (array[x_root] >= array[y_root]) {
            array[y_root] += array[x_root];
            array[x_root] = y_root;
                                //  cout << f(i, j) << ' ' << new_place << '\n';
                    /*cout << "horiz =========\n";
                    for (auto x : hor) {
                        cout << x << ' ';
                    }
                    cout << "\n vertical ========\n";
                    for (auto y : vert) {
                        cout << y <<'\n';
                    }*/
                    // cost += weight;
        } else {
            array[x_root] += array[y_root];
            array[y_root] = x_root;
            // cout << array[x_root] << ' ' << array[y_root] << '\n';
            // cout << temp_x << ' ' << y_root << '\n';
                    // cout << array[x_root] << ' ' << array[y_root] << '\n';
            // cout << temp_x << ' ' << y_root << '\n';
        }
        return true;
    }
    void find_all_dists() {
        for (int i = 1; i <= num_vertices; ++i) {
            for(int j = i + 1; j <= num_vertices; ++j) {
            }
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
                int temp = f(i, j);
                if (!Union(temp, new_place, ancestors)) {
                    continue;
                } else {
                            // edge temp_ = {to, from, cost, 0};
                    answer.push_back({i, j, weight});
                }
            }
        }
    }
    void solve_2(vector<edge>& routes) {
        for (auto &route : routes) {
            if (route.counted == 1) {
                // cout << "we are here\n";
                     // edges.push_back({i, j, distance(x_axis[i], x_axis[j], y_axis[i], y_axis[j])});
                route.counted = 2;
                temp = 0;
                int num = 0;
                vector<int> copied_parent(vertices + 1, -1);
                for (auto &route_ : routes) {

                    if (route_.counted == 2) continue;
                    if (Union(route_.from, route_.to, copied_parent)) {
                        temp += route_.dist;
                        num++;
                        // cout << route_.dist << '\n';
                        // cout << "we are here\n";
                    }
                }
                if (num == vertices - 1) candidates.insert(temp);
                route.counted = 1;
            }
        }
    }
    void solve (vector<edge>& routes) {
        sort(routes.begin(), routes.end());
        for (auto &route : routes) {
            if (Union(route.from, route.to, ancestors)) {
                route.counted = 1;
                ans1 += route.dist;
            }
        }
        solve_2(routes);
        cout << min(ans1, *candidates.begin()) << ' ' << max(ans1, *candidates.begin()) << '\n';
    }
};

int main() {
    int num_schools, num_routes;
    cin >> num_schools >> num_routes;
    Graph g(num_schools);
    int from, to, cost;
    vector<edge> routes;
    for (int i = 0; i < num_routes; ++i) {
        cin >> from >> to >> cost;
        edge temp = {from, to, cost, 0};
        routes.push_back(temp);
        // routes.push_back(temp_);
                            // (Union(route_.from, route_.to)) ? cout << "yes\n" : cout << "no\n";
                    // cout << find(route_.from, ancestors) << ' ' << find(route_.to, ancestors) << '\n';
                    /*if (route_.counted == 2) {
                        continue;
                    }*/
                                    // cout << route.from << ' ' << route.to << ' ' << route.counted << '\n';
                                // if (temp != 0) candidates.insert(temp);
                /*cout << temp << '\n';
                for (auto x : candidates) {
                    cout << x << ' ';
                }
                cout << '\n';*/
    }
    g.solve(routes);
}
