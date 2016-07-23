#include <iostream>
#include <vector>
using namespace std;

int main () {
    string reg = "x?y*z";
    string s = "xaylmz";
    vector< vector<int> > dp (s.length()+1, vector<int>(reg.length()+1, 0));
    //dp[0][0] = '' and ''
    dp[0][0] = 1;
    for (int j = 1; j < reg.length()+1; ++j) {
        dp[0][j] = 0;
    }
    for (int i = 1; i < s.length()+1; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 1; i < s.length()+1; ++i) {
        for (int j = 1; j < reg.length()+1; ++j) {
            if (reg[j] == '?' || reg[j] == s[i]) {
                dp[i][j] = dp[i-1][j-1];
            } else if (reg[j] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            } else {
                dp[i][j] = 0;
            }
        }
    }
    //match = 1, not match = 0
    cout << dp[s.length()][reg.length()] << endl;
    return 0;
}
