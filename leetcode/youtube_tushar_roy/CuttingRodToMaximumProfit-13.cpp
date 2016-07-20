#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> profit{0,2,5,7,8};
    int total = 5;
    vector<vector<int>> dp(profit.size(), vector<int>(total+1, 0));
    for (int j = 0; j <= total; ++j) {
        if (j >= 1) {
            dp[1][j] = profit[1] * j;
        }
    }
    for (int i = 2; i < profit.size(); ++i) {
        for (int j = 1; j <= total; ++j) {
            if (i <= j) {
                dp[i][j] = max( dp[i-1][j], dp[i][j-i]+profit[i] );
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for (int i = 1; i < profit.size(); ++i) {
        for (int j = 1; j <= total; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[profit.size()-1][total] << endl;
    return 0;
}
