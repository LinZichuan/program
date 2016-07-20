#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>> rec{ {2,1,-3,-4,5}, {0,6,3,4,1}, {2,-2,-1,4,-5}, {-3,3,1,0,3} };
    int maxLeft, maxRight, maxUp, maxDown;
    int currSum;
    int row = rec.size();
    int col = rec[0].size();
    for (int i = 0; i < col; ++i) {
        vector<int> sum(row, 0);
        for (int j = i; j < col; ++j) {
            for (int r = 0; r < row; ++r) {
                sum[r] += rec[r][j];
            }
            //1D Kadane Algorithm
            int tmpsum = 0;
            int maxsum = INT_MIN;
            int maxup, maxdown;
            for (int r = 0; r < row; ++r) {
                tmpsum += sum[r];
                if (tmpsum > maxsum) {
                    maxsum = tmpsum;
                    maxdown = r;
                }
                if (tmpsum <= 0) {
                    tmpsum = 0;
                    maxup = r + 1;
                }
            }
            if (maxsum > currSum) {
                currSum = maxsum;
                maxUp = maxup;
                maxDown = maxdown;
                maxLeft = i;
                maxRight = j;
            }
        }
    }
    cout << maxLeft << "," << maxUp << "," << maxRight << "," << maxDown << endl;
    cout << currSum << endl;
    return 0;
}
