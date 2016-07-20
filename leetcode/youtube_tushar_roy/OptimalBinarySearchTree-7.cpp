#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> value{10, 12, 16, 21};
    vector<int> cost{4, 2, 6, 3};
    vector<vector<int>> dp(value.size(), vector<int>(value.size(), 0));
    vector<vector<int>> root(value.size(), vector<int>(value.size(), -1));
    for (int i = 0; i < value.size(); ++i) {
        dp[i][i] = cost[i];
        root[i][i] = i;
    }
    for (int l = 2; l <= value.size(); ++l) {
        for (int i = 0; i < value.size(); ++i) {
            if (i+l > value.size()) continue;
            int currcost = 0;
            for (int j = i; j < i+l; ++j) 
                currcost += cost[j];
            vector<int> tmp(l, 0);
            for (int j = i; j < i+l; ++j) {
                tmp[j-i] = ((j-1>=0)?dp[i][j-1]:0) + ((j+1<i+l)?dp[j+1][i+l-1]:0);
            }
            auto it = min_element(tmp.begin(), tmp.end());
            int pos = it - tmp.begin() + i;
            currcost += *it;
            root[i][i+l-1] = pos;
            dp[i][i+l-1] = currcost;
        }
    }
    int size = value.size() ;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[0][value.size()-1] << endl;
    return 0;
}
