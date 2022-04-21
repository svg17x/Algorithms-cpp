#include <algorithm>

#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
int bbox, bboy, detination_x, dextination_y, number_felxibility, f_x, f_y;
vector<int> X = { 1, 1, 2, 2, -1, -1, -2, -2 };
vector<int> Y = { 2, -2, 1, -1, 2, -2, 1, -1 };

bool is_valid(int i, int j, int k) {
    return (i + X[k] > 0) && (i + X[k] <= bbox) && (j + Y[k] > 0) && (j + Y[k] <= bboy);
}

struct F {
    int x;
    int y;
    F() {
    }
    F(int x_, int y_) : x(x_), y(y_) {
    }
};

class Graph {
public:
    int vertices = 0;
    int sum_;

    vector<set<int> > graph;
    vector<vector<int>> board;
    Graph(int n) : vertices(n) {
        graph.resize(vertices + 1);
        sum_ = 0;
        board.resize(bbox + 1, vector<int>(bboy + 1));
    }

    void Edge_addtional(int parent, int child) {
        graph[parent].insert(child);
        graph[child].insert(parent);
    }

    void fill_board() {
        int count = 0;
        for (int i = 1; i <= bbox; ++i) {
            for (int j = 1; j <= bboy; ++j) {
                board[i][j] = ++count;
            }
        }
    }

    bool bfs(int now, vector<int>& fleas) {
        queue<int> buff;
        buff.push(now);
        vector<int> distances(vertices + 1, numeric_limits<int>::max());
        vector<bool> visited(vertices + 1);
        visited[now] = true;
        distances[now] = 0;
        while (!buff.empty()) {
            int temp = buff.front();
            buff.pop();
            for (auto child : graph[temp]) {
                if (!visited[child]) {
                    visited[child] = true;
                    distances[child] = distances[temp] + 1;
                    buff.push(child);
                }
            }
        }
        for (size_t i = 1; i != fleas.size(); ++i) {
            if (!visited[fleas[i]]) {
                // cout << "we are here" << '\n';
                return false;
            }
            sum_ += distances[fleas[i]];
        }
        return true;
    }

    int f(int x, int y) {
        return (x - 1) * bbox + y;
    }

    vector<int> create_graph(vector<F>& fleas_coords) {
        vector<int> fleas(number_felxibility + 1);
        for (int i = 1; i <= number_felxibility; ++i) {
            fleas[i] = board[fleas_coords[i].x][fleas_coords[i].y];
        }
        for (int i = 1; i <= bbox; ++i) {
            for (int j = 1; j <= bboy; ++j) {
                for (int k = 0; k < 8; ++k) {
                    if (is_valid(i, j, k)) {
                        Edge_addtional(board[i][j], board[i + X[k]][j + Y[k]]);
                    }
                }
            }
        }
        return fleas;
    }

    void solve(vector<F>& fleas_coords) {
        fill_board();
        vector<int> fleas = create_graph(fleas_coords);
        bfs(board[detination_x][dextination_y], fleas) ? cout << sum_<< '\n' : cout << "-1\n";
    }
};

int main() {
    cin >> bbox >> bboy >> detination_x >> dextination_y >> number_felxibility;
    vector<F> fleas_coords(number_felxibility + 1);
    for (int i = 1; i <= number_felxibility; ++i) {
        cin >> f_x >> f_y;
        fleas_coords[i] = {f_x, f_y};
    }
    Graph g(bbox * bboy);
    g.solve(fleas_coords);
}
