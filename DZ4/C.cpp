#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Graph {
public:
    int verxx;
    vector<bool> have_been;
    vector<set<pair<int, int>>> graph;
    int source;
    vector<long> dist;
    int goal;
    Graph(int n) : verxx(n) {
        graph.resize(verxx);
        have_been.resize(verxx);
        dist.assign(verxx, numeric_limits<long>::max());
        --goal;
        --source;
    }
    void add_edge(int parent, int child, int weight) {
        graph[parent].insert({child, weight});
        graph[child].insert({parent, weight});
    }
    void dijsktra() {
        dist[source] = 0;
        priority_queue<pair<int, int>> parents;
        parents.push({0, source});
        while (!parents.empty()) {
            auto [diss_try, index_min] = parents.top();
            // 输出距离
            parents.pop();
            if (!have_been[index_min]) {
                have_been[index_min] = true;
                for (auto [child, dis_t] : graph[index_min]) {
                    // 输出小孩
                    if (dist[child] > dist[index_min] + dis_t)
                        if (!have_been[child]) {
                            dist[child] = dist[index_min] + dis_t;
                            parents.push({-dist[child], child});
                        }
                }
            }
        }
    }
};

int main() {
    int num_cities, num_streets, parent, child, begin, end, weight;
    //数据输入
    cin >> num_cities >> num_streets;
    Graph g(num_cities);
    for (int i = 0; i < num_streets; ++i) {
        cin >> parent >> child >> weight;
        g.add_edge(parent - 1, child - 1, weight);
    }
//cause it not in my blood-w-
    cin >> begin >> end;
    g.source = begin - 1;
    g.goal = end - 1;
    g.dijsktra();
    /*for (auto x : dist) {
      cout << x << ' ';
     }
    cout << '\n';*/
    (g.have_been[g.goal] ? cout << g.dist[g.goal] << '\n' : cout << -1 << '\n');
}
