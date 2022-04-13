#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Graph {
public:
    int verx;
    vector<vector<int> > original_graph;
    set<int> final_graph;
    vector<bool> been;
    Graph(int n) : verx(n) {
        original_graph.resize(verx + 1);
        been.resize(verx + 1);
    }
    void dfs(int pos) {
        been[pos] = true;
        final_graph.insert(pos);
        for (int child : original_graph[pos]) {
            if (!been[child]) {
                dfs(child);
            }
        }
    }
};

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class DFS {
public:
    int verx;
    vector<int> colors;
    vector<int> moment_out;
    vector<int> moment_in;
    int clock = 0;
    vector<vector<int> > original_graph;
    vector<bool> been;
    DFS(int n) : verx(n) {
        colors.resize(verx + 1);
        moment_in.resize(verx + 1);
        moment_out.resize(verx + 1);
        original_graph.resize(verx + 1);
        been.resize(verx + 1);
    }
    void dfs_simple(int pos) {
        been[pos] = true;
        for (int child : original_graph[pos]) {
            if (!been[child]) {
                dfs_simple(child);
            }
        }
    }

    void dfs_color(int pos) {
        clock++;
        moment_in[pos] = clock;
        colors[pos] = 1;
        for (auto child : original_graph[pos]) {
            if (colors[child] == 0) {
                dfs_color(child);
            }
        }
        colors[pos] = 2;
        ++clock;
        moment_out[pos] = clock;
    }
};



int main() {
    int m, n, first, second;
    cin >> m >> n;
    // table -- список смежности
    Graph g(m);
    // read data
    for (int i = 0; i != n; ++i) {
        cin >> first >> second;
        g.original_graph[first].push_back(second);
        g.original_graph[second].push_back(first);
    }
    g.dfs(1);
    cout << g.final_graph.size() << '\n';
    for (int data : g.final_graph) {
        cout << data << ' ';
    }
    cout << '\n';
}
