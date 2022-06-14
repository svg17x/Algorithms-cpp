
#include<iostream>
#include<vector>

using namespace std;

void determine_object_by_number(long long maximum, long long number,
               vector<long long> &prefix, vector<vector<long long>> &t) {
    if (1 == number) {
        for (size_t i = 0; i < prefix.size(); ++i) {
            if (prefix[i]) {
                cout << prefix[i];
            }
        }
        return;
    }


    long long sum = t[0][maximum];
    long long cur_n = 0;
    while (sum < number) {
        sum += t[++cur_n][maximum];
    }

    prefix.push_back(cur_n);

    number -= sum - t[cur_n][maximum];
    number += t[0][maximum] - t[cur_n][maximum];
    --maximum;
    determine_object_by_number(maximum, number, prefix, t);
}


int main() {
    std::ios::sync_with_stdio(false);
    const int constant = 50;
    vector<long long> prefix;
    long long n;
    cin >> n;
    vector<vector<long long>> t(10, vector<long long>(constant, 0));

    // строка - первая цифра
    // столбец  -  число цифр в числе
    // в таблице t считаем кол-во соответствующих чисел

    // 基础
    for (size_t i = 0; i < 10; ++i) {
        t[i][1] = 1;
    }
    // динамика
    for (int j = 2; j < constant; ++j) {
        long long res = 0;
        for (int cur_i = 9; cur_i > -1; --cur_i) {
            res = t[cur_i][j - 1] + res;
            t[cur_i][j] = res;
        }

    }

    determine_object_by_number(constant - 1, n + 1, prefix, t);
    return 0;
}