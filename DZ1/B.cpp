#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > result;

void dfs(vector<vector<int> >& graph, vector<int>& been, int position, int  calculate) {
    been[position] =  calculate;
    result[ calculate].push_back(position);
    for (int child: graph[position]) {
        if (been[child] == 0) {
            dfs(graph, been, child,  calculate);
        }
    }
}

void operation(){
        for (size_t i = 1; i < result.size(); ++i) {
        cout << result[i].size();
        cout << endl;
        for (auto value : result[i]) {
            cout << value << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int verx, edges, left, right;
    cin >> verx >> edges;
    vector<vector<int> > graph(verx + 1);
    vector<int> been(verx + 1);
    for (int i = 0; i != edges; ++i) {
        cin >> left >> right;
        graph[left].push_back(right);
        graph[right].push_back(left);
    }

    int  calculate = 0;
    for (int i = 1; i <= verx; ++i) {
        if (been[i] == 0) {
            ++ calculate;
            result.resize( calculate + 1);
            dfs(graph, been, i,  calculate);
        }
    }

    cout <<  calculate << '\n';
    operation();


}

