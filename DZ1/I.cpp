#include <iostream>

#include <deque>
#include <vector>
#include <algorithm>
#include <cmath> //我总得用根号吧

using namespace std;

double distance_squre(double x1, double y1, double x2, double y2) {
    return (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
}

//有3万个可能的答案

bool to_check_whether_its_right(double angle, vector<vector<int> > &d, vector<int> &c) {
    int n = c.size();
    c.clear();
    c.resize(n);


    for (int g = 0; g < n; ++g) {
        if (0 == c[g]) {
            c[g] = 1;
            deque<int> unvisited;
            unvisited.push_back(g);
            while (!unvisited.empty()) {
                int i = unvisited[0];
                unvisited.pop_front();
                for (int j = 0; j < n; ++j) {
                    if (i == j)
                        continue;
                    if (distance_squre(d[i][0], d[i][1], d[j][0], d[j][1]) >= 4 * angle * angle)
                        continue;
                    if (c[i] == c[j]) {
                        return false;
                    }

                    if (c[j] == 0) {
                        c[j] = 3 - c[i];
                        unvisited.push_back(j);
                    }
                }
            }
        }
    }
    return true;
}


int main() {
    int n;
    double left = 0.0;
    double right = 30000.0;
    double edges = 1e-9;
    //常规数据输入
    cin >> n;
    vector<vector<int> > points_position(n);
    for (int i = 0; i < n; ++i) {
        points_position[i].resize(2);
        cin >> points_position[i][0] >> points_position[i][1];
    }

    vector<int> color(n);
    while (right - left > edges) {
        double angle = (left + right) / 2;
        if (to_check_whether_its_right(angle, points_position, color)) {
            left = angle;
        } else {
            right = angle;
        }
    }
    to_check_whether_its_right(left, points_position, color);
    cout << left << endl;
    for (auto el: color) {
        cout << el << " ";
    }
}
