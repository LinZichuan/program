#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map <int, int> M;
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        int n = strs.size();
        for (int i = 0 ; i < n ; ++i) {
            int bitval = 0;
            int l = strs[i].length();
            for (int j = 0 ; j < l ; ++j) {
                bitval |= (1 << (strs[i][j] - 'a'));
            }
            unordered_map<int,int>::iterator w = M.find(bitval);
            if (w == M.end()) {
                M[bitval] = M.size() + 1;
                vector<string> newvec;
                res.push_back(newvec);
            }
            res[M[bitval]-1].push_back(strs[i]);
        }
        for (int i = 0; i < res.size(); ++i) {
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};
int main (){
    vector<string> strs;
    strs.push_back("a");
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
