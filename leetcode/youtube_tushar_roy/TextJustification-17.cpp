#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> text{"Tushar", "Roy", "likes", "to", "code"};
    int maxlen = 10;
    int num = text.size();
    vector<vector<int>> dp(num, vector<int>(num, INT_MAX));
    for (int i = 0; i < num; ++i) {
        int currlen = 0;
        for (int j = i; j < num; ++j) {
            if (j == i) currlen = text[j].length();
            else currlen += text[j].length() + 1;
            if (currlen > maxlen) {
                dp[i][j] = INT_MAX;
                break;
            }
            dp[i][j] = (maxlen - currlen) * (maxlen - currlen);
        }
    }
    //for (int i = 0; i < num; ++i) {
    //    for (int j = 0; j < num; ++j) {
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    vector<int> dist(num, 0);
    vector<int> res(num, 0);
    dist[0] = dp[0][0];
    res[0] = 0;
    for (int i = 1; i < num; ++i) {
        int tmp = INT_MAX;
        int index = 0;
        for (int j = 0; j < i; ++j) {
            if (dist[j] < INT_MAX && dp[j+1][i] < INT_MAX) {
                if (tmp > dist[j] + dp[j+1][i]) {
                    tmp = dist[j] + dp[j+1][i];
                    index = j;
                }
            }
        }
        dist[i] = tmp;
        res[i] = index;
    }
    for (int i: dist) cout << i << " ";
    cout << endl;
    for (int i: res) cout << i << " "; 
    cout << endl;
    int pos = res[num-1];
    vector<int> newline;
    newline.push_back(pos);
    while (pos != 0) {
        pos = res[pos];
        newline.push_back(pos);
    }
    for (int i = 0; i < newline.size(); ++i) {
        cout << newline[i] << " ";
    }
    cout << endl;
    vector<string> resstr;
    int start = 0;
    for (int i = newline.size()-1; i >= 0; --i) {
        int stop = newline[i];
        string tmp = text[start];
        for (int j = start+1; j <= stop; ++j) {
            tmp += " " + text[j];
        }
        resstr.push_back(tmp);
        start = newline[i] + 1;
    }
    if (start <= num-1) {
        string tmp = text[start];
        for (int j = start+1; j < num; ++j) {
            tmp += " " + text[j];
        }
        resstr.push_back(tmp);
    }
    for_each( resstr.begin(), resstr.end(), [](string s) {cout << s << endl;} );
    return 0;
}
