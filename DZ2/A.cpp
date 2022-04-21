#include <iostream>
#include <vector>

using namespace std;

class TuOpU_sOrT {
public:
    int verx;
    int clock = 0;

    vector<int> colors;
    vector<int> moment_in;
    vector<int> moment_out;

    vector<int> answer;

    vector<vector<int> > graph;
    vector<bool> visited;

    TuOpU_sOrT(int n) : verx(n) {
        //大大拓扑
        answer.resize(verx + 1);
        colors.resize(verx + 1);
        moment_in.resize(verx + 1);
        moment_out.resize(verx + 1);
        graph.resize(verx + 1);
        visited.resize(verx + 1);
    }

    void dfs_simple(int position) {
        visited[position] = true;
        for (int child : graph[position]) {
            int temp = child;
            int a = visited[temp];
            switch (a) {
                case 1:
                dfs_simple(temp);
            }
            //锻炼一下switch的能力了免得忘了我就是这么无聊sorry
        }
        answer.push_back(position);
    }

    void topology() {
        visited.resize(verx + 1);
        answer.clear();
        for (auto x : visited) {
            if (!x) {
                dfs_simple(x);
            }
        }
        reverse(answer.begin(), answer.end());
    }
    
};

void dfs(int vertxss, vector<bool>& visited, vector<int>& stack, vector<vector<int> >& graph) {
    visited[vertxss] = true;
    for (auto child : graph[vertxss]) {
        int temp = child;
        if (!visited[temp]) {
            dfs(temp, visited, stack, graph);
        }
    }
    stack.push_back(vertxss);
}

void topology(int vertxss, vector<vector<int> >& graph, vector<int>& stack, vector<bool>& visited) {
    //小拓扑
    for (int i = 0; i < vertxss; ++i) {
        visited[i] = false;
    }
    for (int i = 1; i <= vertxss; ++i) {
        if (!visited[i]) {
            dfs(i, visited, stack, graph);
        }
    }
    // cout << stack.size() << '\n';只是检查代码
}

bool procedure (int vertxss, vector<int>& color, int& start, vector<vector<int> >& graph) {
    color[vertxss] = 1;
    for (auto child : graph[vertxss]) {
        int temp = child;
        if (color[temp] == 1) {
            start = temp;
            return true;
        }
        if (color[temp] == 0 && procedure(temp, color, start, graph)) return true;
    }
    color[vertxss] = 2;
    return false;
}

int main() {
    int vertxss, edge, first, second;
    cin >> vertxss >> edge;
    vector<vector<int> > graph(vertxss + 1);
    vector<int> color(vertxss + 1);
    vector<int> stack;
    vector<bool> visited(vertxss + 1);
    int start = -1;
    for (int i = 0; i != edge; ++i) {
        cin >> first >> second;
        graph[first].push_back(second);
    }
    for (int i = 1; i <= vertxss; ++i) {
        if (procedure(i, color, start, graph)) {
            break;
        }
    }
    if (start == -1) {
        topology(vertxss, graph, stack, visited);
        while (!stack.empty()) {
            cout << stack.back() << ' ';
            stack.pop_back();
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }
}
