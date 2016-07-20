class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty())  return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        int res = INT_MIN;
        for (int l = 0; l < c; ++l) {
            vector<int> sums(r, 0);
            for (int j = l; j < c; ++j) {
                for (int i = 0; i < r; ++i) {
                    sums[i] += matrix[i][j];            
                }
                set<int> accuSet;
                int currSum = 0, currMax = INT_MIN;
                accuSet.insert(0);
                for (int sum: sums) {
                    currSum += sum;
                    auto it = accuSet.lower_bound(currSum - k);
                    if (it != accuSet.end()) currMax = max(currMax, currSum - *it);
                    accuSet.insert(currSum);
                }
                res = max(res, currMax);
            }
        }
        return res;
    }
    
};
