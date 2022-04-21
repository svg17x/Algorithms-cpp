#include <iostream>

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

void dfs_very_begining(vector<set<pair<int, int> > >& graph,
                     vector<set<pair<int, int> > >& graph_2,
                     int now,
                     vector<int>& visited, 
                     vector<int>& moment_out, 
                     int& time, 
                     int parent) {
                         //太长了分几行写真是吐了我好累想睡觉呜呜呜呜呜呜但是我爱算法我爱AMI
    time++;
    visited[now] = 1;
    for (auto child : graph[now]) {
        if (!visited[child.first]) {
            graph_2[child.first].insert({now, child.second});
            dfs_very_begining(graph, graph_2, child.first, visited, moment_out, time, child.second);
        } else if (visited[child.first] == 1 && child.second != parent){
            graph_2[child.first].insert({now, child.second});
            graph_2[now].insert({child.first, child.second});
        }
    }
    time++;
    visited[now] = 2;
    moment_out.push_back(now);
}

void dfs_afterwards_yes_iwanna_named_like_this_hooray(int now, 
                      vector<set<pair<int, int> > >& graph,
                      vector<int>& visited, 
                      int calculate_thing_shtuk, 
                      set<int>& result) {
    visited[now] = calculate_thing_shtuk;
    for (auto child : graph[now]) {
        if (!visited[child.first]) {
            dfs_afterwards_yes_iwanna_named_like_this_hooray(child.first, graph, visited, calculate_thing_shtuk, result);
        } else if (visited[child.first] != calculate_thing_shtuk) {
            result.insert(child.second);
        }
    }
}

int main() {
    int vertex, edge, parent, child;
    cin >> vertex >> edge;
    vector<set<pair<int, int> > > graph(vertex + 1);
    for (int i = 1; i <= edge; ++i) {
        cin >> parent >> child;
        graph[parent].insert({child, i});
        graph[child].insert({parent, i});
    }
    vector<set<pair<int, int> > > graph_2(vertex + 1);
    vector<int> visited(vertex + 1);
    vector<int> moment_out(vertex);
    int time = 0;
    for (int i = 1; i <= vertex; ++i) {
        if (!visited[i]) {
            dfs_very_begining(graph, graph_2, i, visited, moment_out, time, -1);
        }
    }
    reverse(moment_out.begin(), moment_out.end());
    visited = vector<int>(vertex + 1);
    set<int> result;
    int counter = 0;
    for (int i = 0; i < vertex; ++i) {
        if (!visited[moment_out[i]]) {
            counter++;
            dfs_afterwards_yes_iwanna_named_like_this_hooray(moment_out[i], graph_2, visited, counter, result);
        }
    }
    cout << result.size() << endl;
    for (auto x : result) {
        cout << x << ' ';
    }
    cout << endl;
}
