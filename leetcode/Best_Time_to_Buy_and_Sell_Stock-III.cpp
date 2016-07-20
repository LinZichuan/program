#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    /*int maxProfit(vector<int>& prices) {
        int hold1=INT_MIN, hold2=INT_MIN, sell1=0, sell2=0;
        for (int i: prices) {
            sell2 = max(sell2, hold2+i);
            hold2 = max(hold2, sell1-i);
            sell1 = max(sell1, hold1+i);
            hold1 = max(hold1, -i);
        }
        return sell2;
    }*/

    int maxProfit(vector<int>& prices) {
        //dp[k,i] = max( dp[k,i-1], dp[k-1,j]+prices[i]-prices[j] ) for (j: 0 ~ i-1)
        int n = prices.size();
        if (n <= 1) return 0;
        vector< vector<int> > dp;
        dp.resize(3);
        dp[0].resize(n, 0);
        for (int k = 1; k <= 2; ++k) {
            dp[k].resize(n, 0);
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    dp[k][i] = max(dp[k][i], max( dp[k][i-1], dp[k-1][j]+prices[i]-prices[j] ));
                }
            }
        }
        return dp[2][n-1];
    }
};


int main() {
    vector<int> prices({6,1,3,2,4,7});
    cout << (new Solution)->maxProfit( prices );

    return 0;
}

