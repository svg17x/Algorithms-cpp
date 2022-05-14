#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <tuple>

using namespace std;

int verxx, edges, num_stations, station, start_points, destination;
vector<int> from;
vector<int> to;


struct compare_to {
    int ind;
    int status;
    compare_to() {
    }
    compare_to(int x, int y) : ind(x), status(y) {
    }
    bool friend operator< (const compare_to temp1, const compare_to temp2) {
        return tie(temp1.ind, temp1.status) < tie(temp2.ind, temp2.status);
    }
};

struct ans {
    int ind;
    int dist;
};

class Graph {
public:
    int verxx;
    ans answer = {0, numeric_limits<int>::max()};
    vector<bool> visited;
    vector<int> diss;
    vector<set<compare_to>> graph;
    Graph(int n) : verxx(n) {
        graph.resize(verxx + 1);
        visited.resize(verxx + 1);
        diss.resize(verxx + 1, numeric_limits<int>::max());
    }
    void AddEdge(int parent, int child, bool status) {
        graph[parent].insert({child, status});
        graph[child].insert({parent, status});

    }
    void fill_graph (vector<compare_to>& stations, size_t size) {
        for (size_t i = 1; i <= size; ++i) {
            for (size_t j = i; j <= size; ++j) {
                if (stations[i - 1].status == stations[j - 1].status) {
                    AddEdge(i, j, false);
                }
                if (stations[i - 1].ind == stations[j - 1].ind) {
                    AddEdge(i, j, true);
                }
            }
        }
    }
    deque<int> buff;
    bool solution() {
        for (auto now : from) {
            buff.push_back(now);
            visited[now] = true;
            diss[now] = 0;
        }
        bfs();
        for (auto child : to) {
            if (visited[child] && diss[child] < answer.dist) {
                answer.dist = diss[child];
                answer.ind = child;
            //如果是子节点就+1这没什么问题吧
            }
        }
        return answer.ind != 0;
    }

    void bfs() {
        while (!buff.empty()) {
            int temp = buff.front();
            buff.pop_front();
            for (auto child : graph[temp]) {
                if (!visited[child.ind]) {
                    visited[child.ind] = true;
                    diss[child.ind] = diss[temp] + child.status;
                    if (child.status) {
                        buff.push_back(child.ind);
                    } else {
                        buff.push_front(child.ind);
                    //我感觉我应该把所有的函数名都搞得很长那样我时候就知道我自己在写什么了
                    //而不是写这么多注释
                    }
                }
            }
        }
    }

};





int main() {
    cin >> verxx >> edges;
    vector<compare_to> stations;
    for (int i = 0; i < edges; ++i) {
        cin >> num_stations;
        for (int j = 0; j < num_stations; ++j) {
            cin >> station;
            stations.emplace_back(station, i);
        }
    }
    size_t size = stations.size();
    Graph g(size);
    //每次生成图都很难受啊都很难受
    g.fill_graph(stations, size);
    cin >> start_points >> destination;
    for (size_t i = 1; i <= stations.size(); ++i) {
        if (stations[i - 1].ind == start_points) {
            from.push_back(i);
                //测试输出失败
        }
        if (stations[i - 1].ind == destination) {
            to.push_back(i);
            //测试输出成功
        }
    }
    (g.solution()) ? cout << g.answer.dist << '\n' : cout << "-1\n";
        //答案啊就
}
