#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a = "abcdaf";
    string b = "zbcdf";
    int lena = a.length();
    int lenb = b.length();
    vector<vector<int>> dp(lena, vector<int>(lenb, 0));
    int maxlen = 0;
    int pos_in_a = 0;
    for (int i = 0; i < lena; ++i) {
        for (int j = 0; j < lenb; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                if (dp[i][j] > maxlen) {
                    pos_in_a = j;
                }
                maxlen = max(maxlen, dp[i][j]);
            }
        }
    }
    string substring = a.substr(pos_in_a-maxlen+1, maxlen);
    cout << substring << endl;
    cout << maxlen << endl;
    return 0;
}
