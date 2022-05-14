#include <iostream>

#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#include <cmath>

using namespace std;

struct Coord {
    int x;
    int y;
    Coord(int x_, int y_) : x(x_), y(y_) {
    }
    Coord() {}
    bool friend operator<(const Coord c1, const Coord c2) {
        return tie(c1.x, c1.y) < tie(c2.x, c2.y);
    }
};
class Graph {
public:
    int num_towns;
    vector<set<vector<int>>> graph;
    int answer = 0;
    vector<int> dist;
    vector<bool> visited;
    int copied_answer = 0;
    bool status = true;
    Graph(int n) : num_towns(n){
        graph.resize(num_towns + 1);
    }
    void add_edge(int city_1, int city_2, int schedule, int duration) {
        graph[city_1].insert({city_2, schedule, duration});
    }
    int dijkstra(int begin, int end, int global_time) {
        priority_queue<Coord> buff;
        visited.assign(num_towns + 1, false);
        dist.assign(num_towns + 1, numeric_limits<int>::max());
        dist[begin] = global_time;
        buff.push({-global_time, begin});
        while (!buff.empty()) {
            auto[temp_dist, temp_index] = buff.top();
            buff.pop();
            if (!visited[temp_index]) {
                visited[temp_index] = true;
                for (auto child: graph[temp_index]) {
                    if (!visited[child[0]]) {
                        bool can_go_now = dist[temp_index] % child[1] == 0;
                        auto temp = ceil(dist[temp_index] * 1.0 / child[1]) * child[1];
                        if (can_go_now && dist[child[0]] > dist[temp_index] +  child[2]) {
                            dist[child[0]] = dist[temp_index] +  child[2];
                            buff.push({-dist[child[0]], child[0]});
                        }
                        else if (!can_go_now && dist[child[0]] > temp + child[2]){
                            dist[child[0]] = temp + child[2];
                            buff.push({-dist[child[0]], child[0]});
                        }
                    }
                }
            }
        }
        return (!visited[end]) ? -1 : dist[end];
    }
    void solve(int num_cities, vector<int>& needed) {
        for (int i = 0; i < num_cities - 1 && status; ++i) {
            answer = dijkstra(needed[i], needed[i + 1], answer);
            if (copied_answer > answer) {
                status = false;
                answer = -1;
                break;
            } else {
                copied_answer = answer;
            }
        }
    }
};
int main() {
    int num_towns, num_buses, city1, city2, schedule, duration;
    cin >> num_towns >> num_buses;
    Graph g(num_towns);
    for (int i = 0; i < num_buses; ++i) {
        cin >> city1 >> city2 >> schedule >> duration;
        g.add_edge(city1, city2, schedule, duration);
                            /*for (auto x : dist) {
                             * cout << x << ' ';
                             * }
                             * cout << '\n';*/       
    }
    int num_cities;
    cin >> num_cities;
    vector<int> needed(num_cities);
    for (int i = 0; i != num_cities; ++i) {
        cin >> needed[i];
        // cout << copied_answer << ' ' << answer << '\n';
        // cout << copied_answer << ' ' << answer << '\n';
        /*for (auto x : buff) {
              cout << x << ' ';
          }
        cout << '\n';*/
    }
    g.solve(num_cities, needed);
    cout << g.answer << '\n';
}
