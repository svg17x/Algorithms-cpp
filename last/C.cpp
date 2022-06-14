#include <iostream>
#include <vector>
#include <string>

using namespace std;

string sss = "0123456789abcdefghijklmnopqrstuvwxyz";
int num;
int k;

void print(vector<int> &v){
    for(auto element : v) {
        cout << '\n';
    }
        int i = num - 1;
        while (i >= 0 and v[i] ==0) {
            v[i] = k - 2;
            --i;
        }
        if (i<0)
        return;
        else{
            --v[i];
            print(v);
        }
    }
    
int main(){
        std::ios::sync_with_stdio(false);
        cin >> num;
        cin >> k;
        vector<int> v(num, k-1);
        print(v);
}
