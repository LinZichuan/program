#include <iostream>
#include <vector>
using namespace std;


int main() {
    string s = "agbdba";
    int len = s.length();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for (int i = 0; i < len; ++i) {
        dp[i][i] = 1;
    }
    for (int l = 2; l <= len; ++l) {
        for (int i = 0; i < len; ++i) {
            if (i+l > len) continue;
            int start = i;
            int stop = i + l - 1;
            if (s[start] == s[stop]) {
                dp[start][stop] = 2 + ( (stop-1>=start+1) ? dp[start+1][stop-1]: 0 );
            } else {
                dp[start][stop] = max( dp[start][stop-1], dp[start+1][stop] );
            }
        }
    }
    cout << dp[0][len-1] << endl;
    return 0;
}
