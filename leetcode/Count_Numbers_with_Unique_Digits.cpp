#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 10;
        if (n > 10) n = 10;
        //dp[i] = dp[i-1] + 9*9*8*...*(11-n)
        for (int i = 2; i <= n; ++i) {
            int rest = 9, factor = 9;
            for (int j = 1; j < i; ++j) {
                rest *= factor;
                factor --;
            }
            dp[i] = dp[i-1] + rest;
        }
        return dp[n];
    }
};

int main() {
    cout << (new Solution)->countNumbersWithUniqueDigits(3) << endl;
    return 0;
}
