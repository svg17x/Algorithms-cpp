#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Graph {
public:
    int vertices;
    bool orientation = true;
    vector<vector<size_t> > graph;
    Graph(int n, bool direct) : vertices(n), orientation(direct) {
        graph.resize(vertices + 1);
    }
    void AddEdge(int a, int b) {
        graph[a].push_back(b);
        if (orientation)
            graph[b].push_back(a);
    }
//三大未解之谜之为什么我的代码不工作，为什么我的代码工作，为什么你的代码在我这里不工作
    void dfs_1(vector<int>& visited, 
               int now, 
               int parent, 
               Graph& second, 
               vector<int>& order) {
        visited[now] = 1;
        bool status = true;
        for (int child : graph[now]) {
            if (!visited[child]) {
                second.AddEdge(child, now);
                dfs_1(visited, child, now, second, order);
            } else if (visited[child] == 1 && child != parent) {
                second.AddEdge(child, now);
            } else if (child == parent && !status) {
                second.AddEdge(child, now);
            } else if (child == parent && status) {
                status = false;
            }
        }
        order.push_back(now);
        visited[now] = 2;
    }

    void dfs_2(vector<int>& t_out, int color, int now) {
        t_out[now] = color;
        for (int child : graph[now]) {
            if (t_out[child] == 0) {
                dfs_2(t_out, color, child);
            }
        }
    }

    int bridge(int verx, vector<int>& order, vector<pair<int, int> >& answer) {
        //most明天小测我还没睡觉我在干嘛
        //你只是看起来很努力系列
        int count = 0;
        vector<int> t_out(verx + 1);
        int color = 1;
        for (auto vertex : order) {
            if (t_out[vertex] == 0) {
                dfs_2(t_out, color, vertex);
                ++color;
            }
        }
        for (auto & i : answer) {
            if (t_out[i.first] != t_out[i.second]) {
                ++count;
            }
        }
        return count;
    }
};



void solve(Graph& oriented_graph, vector<pair<int, int> >& answer) {
    vector<pair<int, int> > m_edge;
    for (size_t i = 0; i < answer.size(); ++i) {
        auto x = oriented_graph.graph[answer[i].first];
        bool first_condition = find(x.begin(), x.end(), answer[i].second) != x.end();
        auto y = oriented_graph.graph[answer[i].second];
        bool second_condition = find(y.begin(), y.end(), answer[i].first) != y.end();
        if (first_condition && second_condition) {
            if (find(m_edge.begin(), m_edge.end(), answer[i]) == m_edge.end()) {
                m_edge.push_back(answer[i]);
                cout << answer[i].first << ' ' << answer[i].second << '\n';
            } else {
                cout << answer[i].second << ' ' << answer[i].first << '\n';
            }

        } else if (first_condition) {
            cout << answer[i].first << ' ' << answer[i].second << '\n';
        } else if (second_condition) {
            cout << answer[i].second << ' ' << answer[i].first << '\n';
        }
    }
}
// id ont have any energy。
int main() {
    //按照朝里进行一些数据的收录
    int verx, num_edges, parent, child;
    cin >> verx >> num_edges;
    Graph no_oriented_g(verx, true);
    vector<pair<int, int> > answer;
    for (int i = 0; i < num_edges; ++i) {
        cin >> parent >> child;
        no_oriented_g.AddEdge(parent, child);
        answer.emplace_back(parent, child);
    }
    vector<int> visited(verx + 1);
    vector<int> order;
    Graph oriented_graph(verx + 1, false);
    for (int i = 1; i <= verx; ++i) {
        if (visited[i] == 0) {
            no_oriented_g.dfs_1(visited, i, 0, oriented_graph, order);
        }
    }
    reverse(order.begin(), order.end());
    int count = oriented_graph.bridge(verx, order, answer);
    if (count != 0) {
        cout << 0 << endl;
    }
    else {
        solve(oriented_graph, answer);
    }
}
