#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //148ms
        vector< int > dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]); //take or not take
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
        //180ms
        //vector< vector<int> > dp(coins.size(), vector<int>(amount+1, amount+1));
        //for (int j = 0; j <= amount; ++j) {
        //    if (j % coins[0] == 0) {
        //        dp[0][j] = j / coins[0];
        //    }
        //}
        //for (int i = 0; i < coins.size(); ++i) {
        //    dp[i][0] = 0;
        //}
        //for (int i = 1; i < coins.size(); ++i) {
        //    for (int j = 0; j <= amount; ++j) {
        //        if (coins[i] <= j) {
        //            dp[i][j] = min( dp[i-1][j], 1+dp[i][j-coins[i]] );
        //        } else {
        //            dp[i][j] = dp[i-1][j];
        //        }
        //    }
        //}
        //return dp[coins.size()-1][amount] > amount ? -1 : dp[coins.size()-1][amount];
    } 
};

int main() {
    vector<int> coins{2,5,10,1};
    int amount = 27;
    cout << (new Solution()) -> coinChange(coins, amount) << endl;
    return 0;
   
}
