#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        vector<vector<int> > res;
        for (int i = 0 ; i < n; ++i) {
            vector<int> line;
            for (int j = 0; j < n; ++j) {
                line.push_back(matrix[n-1-j][i]);    //x1=n-y2-1 && y1=x2
            }
            res.push_back(line);
        }
        matrix = res;
    }
};

void printA(vector<vector<int> >& A) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
}
int main() {
    vector<vector<int> > A;
    for (int i = 0; i < 5; ++i) {
        vector<int> l(5,i);
        A.push_back(l);
    }
    printA(A);
    cout << "-------------\n";
    (new Solution())->rotate(A);
    printA(A);
    return 0;
}
