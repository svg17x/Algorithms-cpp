#include <iostream>

#include <vector>
#include <cmath>
#include <limits>

using namespace std;

vector<int> X = {1, 0, -1, 0, 0, 0 };
vector<int> Y = {0, 1, 0, -1, 0, 0 };
vector<int> Z = {0, 0, 0, 0, 1, -1 };
// 右 上 左 下
//下一个-前一个

struct coord {
    int x{}, y{}, z{};
    coord() {}
    coord(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {
    }
};

class Graph {
public:
    vector<vector<vector<int> > > distances;
    int squares;
    coord i_dont_want_bluaberries_on_my_ice_cream_cake;
    vector<vector<coord> > dist;
    int answer;
    Graph(int squares) : squares(squares) {
        distances.resize(squares + 2,
                         vector<vector<int> >(squares + 2,
                                             vector<int>(squares + 2, -1)));
        answer = 0;
        dist.resize(pow(distances.size(), 3) + 1);
    }
    void input(char symbol, int k, int j, int i) {
        if (symbol == '.') {
            distances[k][j][i] = pow(distances.size(), 3);
        } else if (symbol == '#') {
            distances[k][j][i] = -1;
        } else {
            distances[k][j][i] = 0;
            i_dont_want_bluaberries_on_my_ice_cream_cake.x = k;
            i_dont_want_bluaberries_on_my_ice_cream_cake.y = j;
            i_dont_want_bluaberries_on_my_ice_cream_cake.z = i;
        }
    }

    void bfs() {
        while (!dist[answer].empty()) {
            for (coord child : dist[answer]) {
                for (int i = 0; i < 6; ++i) {
                    if (distances[child.x + X[i]][child.y + Y[i]][child.z + Z[i]] == pow(distances.size(), 3)) {
                        distances[child.x + X[i]][child.y + Y[i]][child.z + Z[i]] = distances[child.x][child.y][child.z] + 1;
                        dist[distances[child.x + X[i]][child.y + Y[i]][child.z + Z[i]]].push_back({child.x + X[i], child.y + Y[i], child.z + Z[i]});
                    }
                }
            }
            ++answer;
        }
    }

    int solve() {
        bfs();
        int answer = numeric_limits<int>::max();
        for (auto block : distances) {
            for (auto array : block) {
                if (array[1] > -1 && array[1] < answer) {
                    answer = array[1];
                }
            }
        }
        return answer;
    }
};

int main() {
    int n;
    cin >> n;
    char symbol;
    Graph graph(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                cin >> symbol;
                graph.input(symbol, k, j, i);
            }
        }
    }
    graph.dist[0].push_back(graph.i_dont_want_bluaberries_on_my_ice_cream_cake);
    cout << graph.solve() << '\n';
}
