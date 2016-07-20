#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> coins{1,2,3};
    int total = 5;
    vector<vector<int>> dp(coins.size(), vector<int>(total+1, 0));
    for (int i = 0; i < coins.size(); ++i) {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= total; ++j) {
        if (coins[0] <= j) {
            dp[0][j] = dp[0][j-coins[0]];
        }
    }
    for (int i = 1; i < coins.size(); ++i) {
        for (int j = 1; j <= total; ++j) {
            if (coins[i] <= j) {
                dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j] ;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[coins.size()-1][total] << endl;
    return 0;
}
