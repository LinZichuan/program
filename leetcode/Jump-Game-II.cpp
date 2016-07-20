#include <iostream>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        /* Greedy
         * record maxrange in every new set.
         * and iterate nums(i~maxrange) to update maxrange.
         * when maxrange >= n-1, we find the min step.
        */
        int n = nums.size();
        if (n == 1) return 0;
        int step = 0;
        int maxrange = nums[0];  
        for (int i = 0; i < n; ++i) {
            step++;
            int tmp = maxrange;
            for (int j = i; j <= tmp; ++j) {
                if (j+nums[j] > maxrange) {
                    maxrange = j+nums[j];
                }
            }
            i = tmp;
        }
        return step;
    }
};


int main() {
    return 0;
}
