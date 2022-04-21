#include <vector>
#include <iostream>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> graph;
    vector<bool> visited;
    int ans;
    vector<int> children;
    vector<int> parents;
    explicit Graph(int vertices) : vertices(vertices) {
        graph.resize(vertices + 1);
        visited.resize(vertices + 1);
        children.resize(vertices + 1);
        parents.resize(vertices + 1);
        ans = -1;
    }
    //世界会好吗
    void dfs(int now) {
        visited[now] = true;
        int num_kids = 0;
        for (int child : graph[now]) {
            if (visited[child]) continue;
            parents[child] = now;
            dfs(child);
            ++num_kids;
            num_kids += children[child];
        }
        children[now] = num_kids;
    }

    void procedure() {
        for (int i = 1; i <= vertices; ++i) {
            bool status = true;
            //多一个城市就狗带
            if (graph[i].size() >= 2) {
                if (i != 1) {
                    int num_children = children[1] - children[i];
                    for (int child : graph[i]) {
                        if ((child != parents[i]) &&
                        (num_children != 1 + children[child])) {
                            status = false;
                            break;
                        }
                    }
                } else {
                    int num_children = children[graph[1][0]];
                    for (int child : graph[i]) {
                        if (num_children != children[child]) {
                            status = false;
                            continue;
                        }
                    }
                }
                if (status) {
                    ans = i;
                    break;//up with me
                }
            }
        }
    }
    void solve() {
        if (vertices <= 2) {
            cout << -1 << '\n';
            return;
        }
        dfs(1);
        procedure();
        cout << ans << '\n';
    }
};

int main() {
    // fstream input("input.txt");
    int vertices;
    cin >> vertices;
    Graph graph(vertices);
    for (int i = 1; i < vertices; ++i) {
        int parent, child;
        cin >> parent >> child;
        //输出事情
        graph.graph[parent].push_back(child);
        graph.graph[child].push_back(parent);
    }
    graph.solve();
}
