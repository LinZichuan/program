#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos = nums.size()-1;
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] > nums[i+1]) {
                pos = i;
                break;
            }
        }
        int prelen = nums.size()-(pos+1);
        int postlen = nums.size()-prelen;
        auto it = lower_bound(nums.begin(), nums.begin()+postlen, target);
        if (it != nums.end() && *it == target) return it-nums.begin();
        it = lower_bound(nums.begin()+pos+1, nums.end(), target);
        if (it != nums.end() && *it == target) return it-nums.begin();
        return -1;
    }
}; 
int main() {
    vector<int> nums({1});
    cout << (new Solution())->search(nums, 0) << endl;
    return 0;
}
