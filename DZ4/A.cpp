#include <iostream>

#include <limits>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class DJ {
public:
    int verxx;
    vector<bool> have_been;
    vector<set<pair<int, int>>> graph;
    int source;
    vector<long> diss;
    int goal;
    //她社恐她谁都躲
    DJ(int n) : verxx(n) {
        graph.resize(verxx + 1);
        have_been.resize(verxx + 1);
        diss.assign(verxx + 1, numeric_limits<long>::max());
    }
    void add_edge(int parent, int child, int weight) {
        graph[parent].insert({child, weight});
        graph[child].insert({parent, weight});
    }
    void dijkstra() {
        diss[source] = 0;
        priority_queue<pair<int, int>> parents;
        parents.push({0, source});
//这个边可能喜欢那个点但是我一定不喜欢那个边
        while (!parents.empty()) {
            auto [dist_temp, index_temp] = parents.top();
            parents.pop();
            if (!have_been[index_temp]) {
                have_been[index_temp] = true;
                for (auto [child, dis_t] : graph[index_temp]) {
                    if (diss[child] > diss[index_temp] + dis_t)
                        if (!have_been[child]) {
                            diss[child] = diss[index_temp] + dis_t;
                            parents.push({-diss[child], child});
                        }
                }
            }
        }
    }
};

class Graph {
public:
    int verxx;
    vector<vector<int>> graph;
    int source;
    int goal;
    Graph(int n, int start_point, int end) : verxx(n), source(start_point), goal(end) {
        graph.resize(verxx, vector<int>(verxx));
    }

    void add_edge(int parent, int child, int weight) {
        graph[parent][child] = weight;
    }
    void dijsktra() {
        vector<int> diss(verxx, numeric_limits<int>::max());
        diss[source] = 0;
        vector<bool> have_been(verxx);
        int try_min_diss = 0;
        int try_min_index = source;
        //一些尝试方案
        while (try_min_diss < numeric_limits<int>::max()) {
            int now = try_min_index;
            have_been[now] = true;
            for (int i = 0; i < verxx; ++i) {
                if (graph[now][i] != -1 && diss[now] + graph[now][i] < diss[i]) {
                    diss[i] = diss[now] + graph[now][i];
                    //王天翔................
                }
            }
            try_min_diss = numeric_limits<int>::max();
            for (int i = 0; i < verxx; ++i) {
                if (!have_been[i] && diss[i] < try_min_diss) {
                    try_min_diss = diss[i];
                    try_min_index = i;
                    //我完蛋了我陷入爱河了
                }
            }
        }
        (diss[goal] != numeric_limits<int>::max()) ? cout << diss[goal] << '\n' : cout << -1 << '\n';
    }
};

int main() {
    int num_verxx, start_point, end, weight;
    cin >> num_verxx >> start_point >> end;
    //吸取数据
    Graph g(num_verxx, start_point - 1, end - 1);
    //如果有一日能回到从前
    for (int i = 0; i < num_verxx; ++i) {
        for (int j = 0; j < num_verxx; ++j) {
            cin >> weight;
            g.add_edge(i, j, weight);
        }
    }
    g.dijsktra();
}
