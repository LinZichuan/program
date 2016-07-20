#include <iostream>
#include <vector>
using namespace std;


int main() {
    string a = "abcdef";
    string b = "awced";
    int lena = a.length() + 1;
    int lenb = b.length() + 1;
    vector<vector<int>> dp(lena, vector<int>(lenb, 0));
    for (int i = 0; i < lena; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j < lenb; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i < lena; ++i) {
        for (int j = 1; j < lenb; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min( dp[i-1][j-1], min( dp[i-1][j], dp[i][j-1] ) );
            }
        }
    }
    cout << dp[lena-1][lenb-1] << endl;
    return 0;
}
