#include <iostream>

#include <list>
#include <vector>

using namespace std;

class Graph {
public:
    vector<bool> visited;
    vector<int> time;
    vector<list<int>> graph;
    long answer;
    int counter;
    vector<int> points;
    int verxx;
    Graph(int vertex) : verxx(vertex) {
        answer = 0;
        counter = 0;
        graph.resize(verxx + 1);
        visited.resize(verxx + 1);
        time.resize(verxx + 1);
    }
    void dfs(int current) {
        visited[current] = true;
        answer += time[current];
        ++counter;
        for (auto child : graph[current]) {
            int temp = child;
            if (!visited[temp]) {
                dfs(temp);
            }
        }
        points.push_back(current);
    }
};

int main() {
    int verxx, there_are_some_parts_needed, needed;
    cin >> verxx;
    Graph my_graph(verxx);
    for (int i = 1; i <= verxx; ++i) {
        cin >> my_graph.time[i];
    }
    for (int i = 1; i <= verxx; ++i) {
        cin >> there_are_some_parts_needed;
        for (int j = 0; j < there_are_some_parts_needed; ++j) {
            cin >> needed;
            my_graph.graph[i].push_back(needed);
        }
    }
    my_graph.dfs(1);
    cout << my_graph.answer << " " << my_graph.counter << endl;
    for (auto it = my_graph.points.begin(); it != my_graph.points.end(); ++it) {
        cout << *it << ' ';
    }
        // cout << *my_graph.points.rbegin() << ' ' << *(--my_graph.points.rend()) << '\n';
    cout << '\n';
}
