#include <iostream>

//#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Graph {
public:
    int verxx;
    vector<set<pair<int, int>>> graph;
    int source;
    int goal;
    vector<bool> have_been;
    vector<long> diss;
    Graph(int n) : verxx(n) {
        graph.resize(verxx);
        have_been.resize(verxx);
        diss.assign(verxx, numeric_limits<long>::max());
        --goal;
        --source;
    }
    void add_edge(int parent, int child, int weight) {
        graph[parent].insert({child, weight});
        graph[child].insert({parent, weight});
    }
    void dijsktra() {
        diss[source] = 0;
        priority_queue<pair<int, int>> sum_dist;
        sum_dist.push({0, source});
        vector<int> parents(verxx, -1);
        while (!sum_dist.empty()) {
            auto [try_diss, index_] = sum_dist.top();
            // 尝试打印但没什么用
            sum_dist.pop();
            if (!have_been[index_]) {
                have_been[index_] = true;
                for (auto [child, dis_t] : graph[index_]) {
                    // 有一些不
            // input >> parent >> child >> weight;
            // fstream input("input.txt");
            // input >> num_cities >> num_streets;
                    if (diss[child] > diss[index_] + dis_t)
                        if (!have_been[child]) {
                            /*for (auto x : diss) {
                                cout << x << ' ';
                            }
                            cout << '\n';
                            */
                            diss[child] = diss[index_] + dis_t;
                            sum_dist.push({-diss[child], child});
                            parents[child] = index_;
                        }
                }
            }
        }
        vector<int> path;
        int goal_ = goal;
        while (goal_ != -1) {
            path.push_back(goal_);
            goal_ = parents[goal_];
        }
        reverse(path.begin(), path.end());
        for (auto x : path) {
            // cout << x << ' ';
        }
        // cout << "======\n";
        if (have_been[goal]) {
            cout << diss[goal] << '\n';
            cout << path.size() << '\n';
            for (auto x : path) {
                cout << x + 1 << ' ';
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
};

int main() {
    int num_cities, num_streets, parent, child, begin, end, weight;
    cin >> num_cities >> num_streets;
    Graph g(num_cities);
    for (int i = 0; i < num_streets; ++i) {
        cin >> parent >> child >> weight;
        g.add_edge(parent - 1, child - 1, weight);
        // input >> parent >> child >> weight;
        // fstream input("input.txt");
        // input >> num_cities >> num_streets;
    }
    cin >> begin >> end;
    
    g.source = begin - 1;
    g.goal = end - 1;
    g.dijsktra();
}
