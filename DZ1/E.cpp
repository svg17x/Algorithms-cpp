#include <iostream>
#include <vector>
#include <set>
// #include <fstream>

using namespace std;

void dfs(int position, set<int>& all_the_rest_thing, vector<bool>& vis, vector<vector<int> >&table) {
    vis[position] = true;
    all_the_rest_thing.insert(position);
    for (int verxss : table[position]) {
        if (!vis[verxss]) {
            dfs(verxss, all_the_rest_thing, vis, table);
        }
    }
}

int main() {
    int verx, edge, first, second;
    cin >> verx >> edge;
    vector<vector<int> > graph(verx + 1);
    vector<bool> visited(verx + 1);
    for (int i = 0; i != edge; i++) {
        cin >> first >> second;
        graph[second].push_back(first);
    }

    set<int> all_the_rest_thing;
    dfs(1, all_the_rest_thing, visited, graph);
    for (int data : all_the_rest_thing) {
        cout << data << ' ';
    }
    cout << endl;
}
