/*
 *  First solution : divide and conquer
 * *Second solution: sort and derive the unequation reversely
 * */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size(), res = 0;
        vector<pair<long long, int> > vec;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            vec.push_back(make_pair(sum, i));
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; ++i) {
            cout << vec[i].first << ' ';
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            int index = vec[i].second;
            long long a = vec[i].first + lower - nums[index];
            long long b = vec[i].first + upper - nums[index];
            int x1 = lower_bound(vec.begin(), vec.end(), make_pair(a,0)) - vec.begin(); //return iterator pointing to element not less than val.
            int x2 = upper_bound(vec.begin(), vec.end(), make_pair(b,n)) - vec.begin(); //return iterator pointing to element greater than val.
            //cout << a << ' ' << b << endl;
            //cout << x1 << ' ' << x2 << endl;
            //cout << "---------" << endl;
            for (int j = x1; j < x2; ++j) {
                if (vec[i].second <= vec[j].second) {
                    cout << vec[i].second << ',' << vec[j].second << endl;
                    res ++;
                }
            }
        }
        return res;
    }
};


int main() {
    vector<int> nums({-2,5,-1});
    cout << (new Solution())->countRangeSum(nums, -2, 2) << endl;

    return 0;
}
