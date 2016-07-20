#include <iostream>
#include <vector>
using namespace std;


int main() {
    int eggs = 2;
    int floors = 6;
    vector< vector<int> > dp(eggs+1, vector<int>(floors+1, floors+1) );
    //initialization is very important!!!
    for (int i = 0; i <= eggs; ++i) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= floors; ++j) {
        dp[0][j] = 0;
    }
    for (int j = 1; j <= floors; ++j) {
        dp[1][j] = j;
    }
    for (int i = 2; i <= eggs; ++i) {
        for (int j = 1; j <= floors; ++j) {
            if (i > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                //dp[i][j] = min( 1 + max(dp[i-1][k-1], dp[i][j-k]) )  //break or not break
                for (int k = 1; k <= j; ++k) {
                    dp[i][j] = min( dp[i][j], 1 + max(dp[i-1][k-1], dp[i][j-k]) );
                }
            }
        }
    }
    for (int i = 1; i <= eggs; ++i) {
        for (int j = 1; j <= floors; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
