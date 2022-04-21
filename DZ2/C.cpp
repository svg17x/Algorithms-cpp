#include <iostream>
#include <fstream>

#include <vector>
#include <set>

using namespace std;

class Graph {
private:
    int time;
    int verx;

    vector<vector<int> > graph;
    vector<bool> visited;
    vector<int> moment_in;
    vector<int> numberl;
    set<int> points;

public:
    Graph(int n) : verx(n) {
        graph.resize(verx + 1);
        visited.resize(verx + 1);
        moment_in.resize(verx + 1);
        numberl.resize(verx + 1);//距离啊
        //现在是2:35我因为喝茶晚上睡不着觉我希望我能早点感到非常困
    }

    void create_table (int parent, int child) {
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }

    void dfs(int now, int parent = -1) {
        int num_children = 0;

        visited[now] = true;
        time++;
        moment_in[now] = time;
        numberl[now] = time;

        for (auto child : graph[now]) {
            int temp = child;

            if (temp == parent) {
                continue;
            }
            if (visited[temp]) {
                numberl[now] = min(numberl[now], moment_in[temp]);
            } else {
                dfs(temp, now);
                num_children++;
                numberl[now] = min(numberl[now], numberl[temp]);
                if ((numberl[temp] >= moment_in[now]) && (parent != -1)) {
                    points.insert(now);
                }
            }
        }
        if ((num_children >=2) && (parent == -1)) {
            points.insert(now);
        }
    }

    set<int> solve() {
        time = 1;
        for (int i = 1; i <= verx; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return points;
    }
};

int main() {
    //fstream input("input.txt");
    int verx, edges, parent, child;
    cin >> verx >> edges;
    Graph graph(verx);
    for (int i = 1; i <= edges; i++) {
        cin >> parent >> child;
        //进行一些数据的输入
        graph.create_table(parent, child);
    }
    set<int> answer = graph.solve();
    cout << answer.size() << endl;
    for (auto x : answer) {
        cout << x << endl;
    }
    return 0;
}
