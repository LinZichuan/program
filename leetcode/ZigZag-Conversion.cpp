#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<vector<char> > res(numRows);
        int col = 0;
        int num = 0;
        int len = s.length();
        int row;
        while(num < len) {
            if (col % (numRows-1) == 0) {
                for (int i = 0; i < numRows && num < len; ++i) {
                    res[i].push_back(s[num++]);
                }
                row = numRows-2;
            } else {
                res[row--].push_back(s[num++]);
            }
            col++;
        }
        num = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < res[i].size(); ++j) {
                s[num++] = res[i][j];
            }
        }
        return s;
    }
};
int main() {
    cout << (new Solution())->convert("A", 1) << endl;
    return 0;
}
