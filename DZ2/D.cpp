/*显然是一些concepts///////
  Конденсацией орграфа G':
  顶点是图G的强连通分量
  当且仅当定点之间至少存在一条边，存在G中的弧
   包含在相应的连通组件中*/

#include <iostream>

#include <vector>
#include <map>
#include <set>

using namespace std;

class Graph {
public:
    int i_dont_wanna_count_but_i_have_to;
    int verxx;

    vector<vector<int> > graph_original_poliadakOrder;
    vector<vector<int> > graph_inverse;
    vector<bool> visited;
    vector<int> momtn_out;
    vector<int> order;
    vector<int> components;
    set<pair<int, int> > useful_edges;

    Graph(int n) : verxx(n) {
        graph_original_poliadakOrder.resize(verxx + 1);
        graph_inverse.resize(verxx + 1);
        visited.resize(verxx + 1);
        momtn_out.resize(verxx + 1);
        components.resize(verxx + 1);
        i_dont_wanna_count_but_i_have_to = 0;
    }

    void tableCreater (int parent, int child) {
        graph_original_poliadakOrder[parent].push_back(child);
        graph_inverse[child].push_back(parent);
    }

    void first_dfs(int now) {
        visited[now] = true;
        for (auto child : graph_original_poliadakOrder[now]) {
            int temp = child;
            if (!visited[temp]) {
                first_dfs(temp);
            }
        }
        order.push_back(now);
    }
    void second_dfs(int now) {
        visited[now] = true;
        components[now] = i_dont_wanna_count_but_i_have_to;
        for (auto child : graph_inverse[now]) {
            int temp = child;
            if (!visited[temp])
                second_dfs(temp);
        }
    }

    void clean_visited() {
        visited.clear();
        visited.resize(verxx + 1);
    }

    set<pair<int, int> > solve() {
        for (size_t m = 0; m != graph_original_poliadakOrder.size(); m++) {
            for (size_t n = 0; n != graph_original_poliadakOrder[0].size(); n++) {
                int temp = graph_original_poliadakOrder[m][n];
                if (components[m] != components[temp])
                    useful_edges.insert({components[m], components[temp]});
            }
        }
        return useful_edges;
    }
};

int main() {
    int verxx, edges, parent, child;
    // fstream input("input.txt");
    cin >> verxx >> edges;
    Graph giraff(verxx);
    //m am so sorry m know m should write graph but m do wanna write as giraff

    for (int m = 1; m <= edges; ++m) {
        cin >> parent >> child;
        giraff.tableCreater(parent, child);
    }
    for (int m = 1; m <= verxx; ++m) {
        if (!giraff.visited[m]) {
            giraff.first_dfs(m);
        }
    }
    giraff.clean_visited();
    // m do like pragramming but sometimes m do feel depressed when m cant do things right
    //so add some stupid but funny comments among them is a way  of fighting boredom and keeping my love for programming for me
    for (size_t m = 1; m <= giraff.order.size(); ++m) {
        int vertex = giraff.order[verxx - m];
        if (!giraff.visited[vertex]) {
            giraff.second_dfs(vertex);
            giraff.i_dont_wanna_count_but_i_have_to++;
        }
    }
    // midnight you came pick me up no haedlights--taylor swift
    //midnight I wrote my code without a bright mind--yuxin zheng
    set<pair<int, int> > answer = giraff.solve();
    cout << giraff.i_dont_wanna_count_but_i_have_to << endl;
    for (size_t m = 1; m != giraff.components.size(); ++m) {
        cout << giraff.components[m] + 1 << ' ';
    }
    cout << endl;
    //my little virtual is keep using endl instead of\n
}
