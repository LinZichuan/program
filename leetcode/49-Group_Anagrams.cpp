#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res ;
        unordered_map <string, vector<string> > M;
        int n = strs.size();
        int i = 0 ;
        for (auto s: strs) {
            sort(s.begin(), s.end());
            M[s].push_back(strs[i++]);
        }
        for (auto m: M) {
            sort(m.second.begin(), m.second.end());
            res.push_back(m.second);
        }
        return res;
    }
};
int main (){
    vector<string> strs;
    strs.push_back("bob");
    strs.push_back("boo");
//    strs.push_back("eat");
//    strs.push_back("tea");
//    strs.push_back("tan");
//    strs.push_back("ate");
//    strs.push_back("nat");
//    strs.push_back("bat");
    vector<vector<string> > res = (new Solution()) -> groupAnagrams(strs);
    for (int i = 0 ; i < res.size(); ++i) {
        for (int j = 0 ; j < res[i].size(); ++j) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
