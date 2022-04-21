#include <iostream>

#include <set>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>


using namespace std;


class BFS {
public:
    int verxx = 0;
    int sum_;
    int to;
    vector<int> parent;
    vector<set<int>> graphic;
    BFS(int n) : verxx(n) {
        graphic.resize(verxx + 1);
        sum_ = 0;
        parent.resize(verxx + 1);
    }
    void AddEdge(int parent, int child) {
        graphic[parent].insert(child);
        graphic[child].insert(parent);
    }
    void bfs(int now, vector<int>& fleas) {
        queue<int> buff;
        buff.push(now);
        vector<int> distances(verxx + 1, numeric_limits<int>::max());
        vector<bool> visited(verxx + 1);
        visited[now] = true;
        parent[now] = -1;
        distances[now] = 0;
        while (!buff.empty()) {
            int temp = buff.front();
            buff.pop();
            for (auto child : graphic[temp]) {
                if (!visited[child]) {
                    visited[child] = true;
                    distances[child] = distances[temp] + 1;
                    parent[child] = now;
                    buff.push(child);
                }
            }
        }
        if (!visited[to]) {
            cout << "NO PATH\n";
        } else {
            vector<int> path;
            for (int pos = to; pos != -1; pos = parent[pos])
                path.push_back (pos);
            reverse (path.begin(), path.end());
            cout << "Path: ";
            for (size_t i=0; i<path.size(); ++i)
                cout << path[i] + 1 << " ";
        }
    }
};



class Graph {
public:
    int verxx;
    vector<int> route;

    int terminal, destination, desnice_final;
    vector<int> parents;
    vector<int> distance;
    vector<vector<int>> graphic;
    Graph(int n) : verxx(n) {
        graphic.resize(verxx + 1);
        parents.resize(verxx + 1, -1);
        distance.resize(verxx + 1, numeric_limits<int>::infinity());
    }
    bool bfs() {
        desnice_final = destination;
        if (destination == terminal) {
            distance[destination]= 0;
            return true;
        }
        //
        vector<bool> visited(verxx + 1);
        list<int> buff;
        visited[terminal] = true;
        distance[terminal] = 0;
        //谁困了？我困了
        buff.push_back(terminal);
        while (!buff.empty()) {
            int temp = buff.front();
            buff.pop_front();
            for (auto child : graphic[temp]) {
                if (!visited[child]) {
                    visited[child] = true;
                    distance[child] = distance[temp] + 1;
                    parents[child] = temp;
                    buff.push_back(child);
                    if (child == destination) {
                        return true;
                    }
                    //返回一些
                }
            }
        }
        return false;
    }
    void solve() {
        route.push_back(desnice_final);
        while (parents[desnice_final] > -1) {
            route.push_back(parents[desnice_final]);
            desnice_final = parents[desnice_final];
        }
    }
};

int main() {
    int num_vertices, value;
    // fstream input("input.txt");
    cin >> num_vertices;
    Graph g(num_vertices);
    for (int i = 1; i <= num_vertices; ++i) {
        for (int j = 1; j <= num_vertices; ++j) {
            cin >> value;
            if (value) {
                g.graphic[i].push_back(j);
            }
        }
    }
    /*
    如果可以睡觉我就睡觉
    */
    cin >> g.terminal >> g.destination;
    if (g.bfs()) {
        g.solve();
        cout << g.distance[g.destination] << '\n';
    } else {
        cout << "-1" << '\n';
    }
    //答应答案
}
