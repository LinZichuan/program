/*
    The difference with I problem is that the 1th house and the nth house is neighbor.
    Use dp in 0->n-2 and 1->n-1 respectively.
*/

class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2) 
            return max(nums[0], nums[1]);
        dp.assign(n, 0);
        //0->n-2
        dp[n-2] = nums[n-2];
        dp[n-3] = max(nums[n-3], nums[n-2]);
        for (int i = n-4; i >= 0; --i) {
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }
        int tmp = dp[0];
        //1->n-1
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-2], nums[n-1]);
        for (int i = n-3; i >= 1; --i) {
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }
        return tmp>dp[1]? tmp: dp[1];
    }
};
