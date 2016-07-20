#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
        //dp[k,i] = max(dp[k,i-1], dp[k-1,j]+prices[i]-prices[j])
        //dp[k,i] = max(dp[k,i-1], prices[i]+dp[k-1,j]-prices[j])
        int n = prices.size();
        if (n <= 1) return 0;
        vector< vector<int> > dp;
        
        //if k > n/2, then use greedy strategy!!!!!!
        if (k > n / 2)  return GreedySolve(prices);

        dp.resize(k+1);
        dp[0].resize(n, 0);
        for (int kk = 1; kk <= k; ++kk) {
            dp[kk].resize(n, 0);
            int tmpmax = dp[kk-1][0]-prices[0];
            for (int i = 1; i < n; ++i) {
                dp[kk][i] = max( dp[kk][i-1], prices[i]+tmpmax );
                tmpmax = max( tmpmax, dp[kk-1][i]-prices[i] );
            }
        }
        return dp[k][n-1];
    }
    int GreedySolve(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[i-1]) res += prices[i] - prices[i-1];
        }
        return res;
    }

};


int main() {
    vector<int> prices({6,1,3,2,4,7});
    cout << (new Solution)->maxProfit( prices );

    return 0;
}

