#include <iostream>

#include <list>
#include <vector>
#include <limits>

using namespace std;

class Graph {
public:
    int verx;
    vector<int> route;
    int terminal, there_is_the_midium_destination, final_destination;
    vector<int> parents;
    vector<int> diss;
    vector<vector<int>> graph;
    Graph(int n) : verx(n) {
        graph.resize(verx + 1);
        parents.resize(verx + 1, -1);
        diss.resize(verx + 1, numeric_limits<int>::infinity());
    }

    bool bfs() {
        final_destination = there_is_the_midium_destination;
        if (there_is_the_midium_destination == terminal) {
            diss[there_is_the_midium_destination]= 0;
            return true;
        }
        vector<bool> visited(verx + 1);
        list<int> buff;
        visited[terminal] = true;
        diss[terminal] = 0;
        buff.push_back(terminal);
        while (!buff.empty()) {
            int temp = buff.front();
            buff.pop_front();
            for (auto child : graph[temp]) {
                if (!visited[child]) {
                    visited[child] = true;
                    diss[child] = diss[temp] + 1;
                    parents[child] = temp;
                    buff.push_back(child);
                    if (child == there_is_the_midium_destination) return true;
                }
            }
        }
        return false;
    }
    void solve() {
        //解决最后终点的问题
        route.push_back(final_destination);
        while (parents[final_destination] > -1) {
            route.push_back(parents[final_destination]);
            final_destination = parents[final_destination];
        }
    }
};

int main() {
    //找路
    int num_verxx, znachenie;
    cin >> num_verxx;
    Graph g(num_verxx);
    for (int i = 1; i <= num_verxx; ++i) {
        for (int j = 1; j <= num_verxx; ++j) {
            cin >> znachenie;
            if (znachenie) {
                g.graph[i].push_back(j);
            }
        }
    }
    /*
    :)
    */
    cin >> g.terminal >> g.there_is_the_midium_destination;
    if (g.bfs()) {
        g.solve();
        cout << g.diss[g.there_is_the_midium_destination] << '\n';
        if (g.diss[g.there_is_the_midium_destination] != 0) {
            for (auto it = g.route.rbegin(); it != g.route.rend(); ++it) {
                cout << *it << ' ';
                //*的意思是指针
            }
            cout << '\n';
        }
    } else {
        cout << "-1" << '\n';
    }
}
