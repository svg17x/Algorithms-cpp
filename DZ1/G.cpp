#include <iostream>
#include <vector>

using namespace std;

//树的最深枝桠

void first_we_calculate_like_this(vector<vector<int> >& graph, int now, int parent, vector<int>& in) {
    in[now] = 0;
    for (auto x : graph[now]) {
        if (x == parent) continue;
        first_we_calculate_like_this(graph, x, now, in);
        in[now] = max(in[now], 1 + in[x]);
    }
}

void afterwards_we_found_this(vector<vector<int> >& graph, int now, int parent, vector<int>& in, vector<int>& out) {
    int first_maximation = -1;
    int second_maximation = -1;
    for (auto x : graph[now]) {
        if (x == parent) continue;

        (in[x] >= first_maximation)&&({second_maximation = first_maximation;first_maximation = in[x];})
        ||
        (in[x] > second_maximation)&&({second_maximation = in[x];});//记得加个分号

    }
    for (int child : graph[now]) {
        int a = (child == parent);
        switch (a){
        case 1:
            continue;
        } 
        int deepest = first_maximation;
        if (first_maximation == in[child])
            deepest = second_maximation;
        out[child] = 1 + max(out[now], 1 + deepest);
        afterwards_we_found_this(graph, child, now, in, out);
    }
}

int main() {
    int n, parent, child;
    cin >> n;
    vector<vector<int> > graph(n + 1);

    for (int i = 1; i != n; i++) {
        cin >> parent >> child;
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }

    vector<int> in(n + 1);
    vector<int> out(n + 1);
    first_we_calculate_like_this(graph, 1, 0, in);
    afterwards_we_found_this(graph, 1, 0, in, out);
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        ans = (ans < max(in[i], out[i]) ? max(in[i], out[i]) : ans);
    }
    cout << ans << endl;
}
