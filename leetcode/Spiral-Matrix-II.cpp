#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    Solution() {}
    int n_;
    int num;
    vector<vector<int> > a;
    void fillup(int start) {
        for (int j = start; j < n_-start; ++j) {
            a[start][j] = ++num;
        }
        for (int i = start+1; i < n_-start; ++i) {
            a[i][n_-start-1] = ++num;
        }
        for (int j = n_-start-2; j >= start; --j) {
            a[n_-start-1][j] = ++num;
        }
        for (int i = n_-start-2; i >= start+1; --i) {
            a[i][start] = ++num;
        }
    }
    vector<vector<int> > generateMatrix(int n) {
        n_ = n;
        num = 0;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            a[i].resize(n);
        }
        int times = (n + 1) / 2;
        for (int i = 0; i < times; ++i) {
            fillup(i);
        }
        for (int i = 0 ; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
        return a;
    }
};


int main () {
    int n = 6;
    (new Solution())->generateMatrix(n);
    return 0;
}
