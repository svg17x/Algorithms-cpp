#include <iostream>

#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

struct  anonymous {
    int neigh;
    int innn;
     anonymous() {}
     anonymous(int x, int y) : neigh(x), innn(y) {
    }
    bool friend operator< (const  anonymous temp1, const  anonymous temp2) {
        return tie(temp1.neigh, temp1.innn) < tie(temp2.neigh, temp2.innn);
    }
};
class Graph {
public:
    int verxx;
    vector<bool> visited1;
    vector<int> dist1;
    set<int> answer;
    vector<bool> visited2;
    vector<int> dist2;
    int departure;
    int destination;
    vector<set< anonymous>> graph;
    Graph(int n) : verxx(n) {
        graph.resize(verxx + 1);
        visited1.resize(verxx + 1);
        visited2.resize(verxx + 1);
        dist1.resize(verxx + 1);
        dist2.resize(verxx + 1);
    }
    void AddEdge(int parent, int child, int inn) {
        graph[parent].insert({child, inn});
        graph[child].insert({parent, inn});
    }
    void bfs() {
        queue<int> no_bug_plz;
        no_bug_plz.push(destination);
        dist2[destination] = 0;
        visited2[destination] = true;
        while (!no_bug_plz.empty()) {
            int temp = no_bug_plz.front();
            no_bug_plz.pop();
            for (auto child : graph[temp]) {
                if (!visited2[child.neigh]) {

                //这个case还是不用switch比较好
                    visited2[child.neigh] = true;
                    dist2[child.neigh] = dist2[temp] + 1;
                    no_bug_plz.push(child.neigh);
                }
            }
        }
    }
    void bfs_2() {
        queue<int> no_bug_plz;
        no_bug_plz.push(departure);
        dist1[departure] = 0;
        visited1[departure] = true;
        while (!no_bug_plz.empty()) {
            int temp = no_bug_plz.front();
            no_bug_plz.pop();
            for (auto child : graph[temp]) {
                if (!visited1[child.neigh]) {
                    visited1[child.neigh] = true;
                    dist1[child.neigh] = dist1[temp] + 1;
                    no_bug_plz.push(child.neigh);
                }
            }
        }
    }

    void solve() {
        bfs();
        bfs_2();
        int needed_diss = dist1[destination];
        for (int now = 1; now <= verxx; ++now) {
            for (auto [t, inn] : graph[now]) {
                bool fist_condition = dist1[now] + dist2[t] + 1 == needed_diss;
                bool second_condition = dist1[t] + dist2[now] + 1 == needed_diss;
                if (fist_condition || second_condition) {
                    answer.insert(inn);
                //不是 课上都说了我总不能不会吧
                //我真的不会
                //呵呵
                }
            }
        }
    }
};

int main() {
    int num_verxx, num_edges, parent, child;

    cin >> num_verxx >> num_edges;
    Graph g(num_verxx);
    for (int i = 1; i <= num_edges; ++i) {
        cin >> parent >> child;
        g.AddEdge(parent, child, i);
    }
//第一次知道这个代码可以直接本地保存真好
//或许下次可以直接上传文档呢
    cin >> g.departure >> g.destination;
    g.solve();
    cout << num_edges - g.answer.size() << "\n";
}
