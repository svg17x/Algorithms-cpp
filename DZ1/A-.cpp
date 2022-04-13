#include <iostream>
#include <vector>
#include <set>

using namespace std;

class G {
    public:
    int verx;
    vector<vector<int> > original_graph;
    set<int> final_graph;
    vector<bool> been;
    G(int n) : verx(n) {
        original_graph.resize(verx ++);
        been.resize(verx ++);
    }
    void dfs(int position) {
        been[position] = 1;
        final_graph.insert(position);
        for (int child : original_graph[position]) {
            if (!been[child]) {
                dfs(child);
            }
        }
    }
};

class DFS {
    public:
    int verx;
    vector<int> colors;
    vector<int> moment_in;
    vector<int> moment_out;
    int clock = 0;
    vector<vector<int> > original_graph;
    vector<bool> been;
    DFS(int n) : verx(n) {
        colors.resize(verx ++);
        moment_in.resize(verx ++);
        moment_out.resize(verx ++);
        original_graph.resize(verx ++);
        been.resize(verx ++);
    }
    void dfs_simple(int position) {
        been[position] = true;
        for(int child : original_graph[position]) {
            if (!been[child]) {
                dfs_simple(child);
            }
        }
    }

    void dfs_color(int position) {
        clock++;
        moment_in[position] = clock;
        colors[position] = 1;
        for(auto child : original_graph[position]) {
            if(colors[child] == 0) {
                dfs_color(child);
            }
        }
        colors[position] = 2;
        ++clock;
        moment_out[position] = clock;
    }
};

int main() {
    int a, b, l, r;
    cin >> a >> b;
    //相邻列表点
    G g(a);
    //读取数据
    for (int i = 0; i != b; ++i) {
        cin >> l >> r;
        g.original_graph[l].push_back(r);
        g.original_graph[r].push_back(l);
    }
    g.dfs(1);
    cout << g.final_graph.size() << '\n';
    for (int d : g.final_graph) {
        cout << d << ' ';
    }
    cout << endl;
}
