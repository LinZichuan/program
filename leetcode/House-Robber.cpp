#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int *dp;
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        } 
        if (nums.size() == 2) {
            return max(nums[nums.size()-1], nums[nums.size()-2]);
        }
        dp = new int[nums.size()+1];
        memset(dp, 0, (nums.size()+1)*sizeof(int));
        //dp[i] = max{nums[i]+dp[i+2], dp[i+1]};
        //dp[i] = max money from i house to n house
        dp[nums.size()-1] = nums[nums.size()-1];
        dp[nums.size()-2] = max(nums[nums.size()-1], nums[nums.size()-2]);
        for (int i = nums.size()-3; i >= 0; --i) {
            dp[i] = max(dp[i+1], nums[i]+dp[i+2]);
        }
        return dp[0];
    }
    
};

int main() {
    vector<int> nums({1,2,3,4});
    cout << (new Solution())->rob(nums) << endl;
    return 0;
}
