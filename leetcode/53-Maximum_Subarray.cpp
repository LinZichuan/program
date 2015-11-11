#include <iostream>
#include <vector>
using namespace std;

//先遍历一遍找到sum最大值，再在最大值前面找出最小值，然后最大值－最小值
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int *sum = new int[nums.size()];
        sum[0] = 0;
        int maxval = nums[0];
        int ma = 0;
        for (int i = 1 ; i < nums.size(); ++i) {
            sum[i] = sum[i-1] + nums[i];
            if (sum[i] > maxval) {
                maxval = sum[i];
                ma = i;
            }
        }
        int minval = nums[0];
        int mi = 0;
        for (int i = 1 ; i < ma ; ++i) {
            if (sum[i] < minval) {
                minval = sum[i];
                mi = i;
            }
        }
        if (sum[mi] < 0)
            return sum[ma] - sum[mi];
        else
            return sum[ma];
    }
};
int main() {
    int n[9] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(n, n+9);
    cout << (new Solution()) -> maxSubArray(nums) << endl;
}
