#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > result;

//不要再忘记vector加记号了！！！！！！！！！1

void dfs(vector<vector<int> >& graph, vector<int>& been, int position, int count) {
    been[position] = count;
    result[count].push_back(position);
    //找一些不同的东西
    for (int child: graph[position]) {
        if (been[child] == 0) {
            dfs(graph, been, child, count);
        }
    }
}

int main() {
    // fstream input("input.txt");测试用的无所谓了
    int verx, edges, node_1, node_2;
    cin >> verx >> edges;
    //输入不同的
    vector<vector<int> > graph(verx + 1);
    vector<int> been(verx + 1);
    for (int i = 0; i != edges; ++i) {
        cin >> node_1 >> node_2;
        graph[node_1].push_back(node_2);
        graph[node_2].push_back(node_1);
    }
    int count = 0;
    for (int i = 1; i <= verx; ++i) {
        if (been[i] == 0) {
            count++;
            result.resize(count + 1);
            dfs(graph, been, i, count);
        }
    }
    cout << count << '\n';
    for (size_t i = 1; i < result.size(); ++i) {
        cout << result[i].size() << '\n';
        for (auto value : result[i]) {
            cout << value << ' ';
        }
        cout << '\n';
        //浅浅进行一些答案的打印
    }
}