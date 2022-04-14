#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

    /*void dfs_color(int position) {
        clock++;
        moment_in[position] = clock;
        colors[position] = 1;
        for(auto child : original_graph[position]) {
            if(colors[child] == 0) {
                dfs_color(child);
            }
        }
        colors[position] = 2;
        ++clock;
        moment_out[position] = clock;*/

void dfs(int present, int parent, vector<int>& final, vector<vector<int> >& graph) {
    final[present] = 1;
    for (auto going_through : graph[present]) {
        if (going_through == parent) {
            continue;
        }
        dfs(going_through, present, final, graph);
        final[present] += final[going_through];
    }
}

int main() {
    //fstream input(input.txt);
    int n, parent, child;
    cin >> n;
    vector<vector<int> > graph(n + 1);
    vector<int> final(n + 1);
    // 读取数据
    for (int i = 1; i != n; i++) {
        cin >> parent >> child;
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }
    dfs(1, 0, final, graph);
    for (size_t i = 1; i < final.size(); i++) {
        cout << final[i] << ' ';
    }
    cout << endl;
}
