//Dynamic Programming
#include <iostream>

using namespace std;

int main() {
    vector<int> coins( {1,5,6,8} );
    int total = 11;
    vector< vector<int> > dp;
    dp.resize( coins.size(), vector<int>(total, 0) );
    /*
     * if (j >= coins[i]) dp[i][j] = min( dp[i-1][j], dp[i][j-coins[i]] )
     * else dp[i][j] = dp[i-1][j]
     * 
     */
    for (int i = 1; i < coins.size(); ++i) {
        for (int j = 0; j <= total; ++j) {
            
        }
    }

}
