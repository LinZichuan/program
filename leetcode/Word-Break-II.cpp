#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
    Solution() {}
    int len;
    string os;
    vector<string > res;
    vector<bool> dp;
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        os = s;
        len = s.length();
        dp.assign(len+1, false);
        dp[len] = true;
        //check if position i is possible to be breaked, cut unnecessary search range, otherwise the program will be timeout.
        //from end to front, pre-assert where can be breaked.
        for (int i = len; i >= 1; --i) {
            for (auto word: wordDict) {
                if (i >= word.length() && dp[i] && s.substr(i-word.length(), word.length()) == word) {
                    dp[i-word.length()] = true;
                }
            }
        }
        int start = 0;
        dynamic("", start, wordDict);
        /*for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << endl;
        }*/
        return res;
    }
    void dynamic(string s, int start, unordered_set<string>& wordDict) {
        if (start == len) {
            res.push_back(s);
        }
        for (auto word: wordDict) {
            if (start + word.length() <= len && dp[start+word.length()] && os.substr(start, word.length()) == word) {
                if (start == 0)
                    dynamic(word, start+word.length(), wordDict);
                else
                    dynamic(s+" "+word, start+word.length(), wordDict);
            }
        }
    }
};


int main () {
    //string s = "catsanddog";
    //unordered_set<string> w ( {"cat", "cats", "and", "sand", "dog"} );
    string s = "bb";
    unordered_set<string> w ( {"a", "b", "bbb", "bbbb"} );
    //string s = "a";
    //unordered_set<string> w ( {"a"} );
    (new Solution())->wordBreak(s, w);
    return 0;
}
