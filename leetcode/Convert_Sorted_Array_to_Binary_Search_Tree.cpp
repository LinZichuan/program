#include <iostream>
#include <vector>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return NULL;
        return sortArray(nums, 0, n);
    }
    TreeNode* sortArray(vector<int>& nums, int begin, int end) {
        int n = end - begin;
        int midpos = n / 2 + begin;
        int midvalue = nums[midpos];
        TreeNode* node = new TreeNode(midvalue);
        if (midpos > begin) node->left = sortArray(nums, begin, midpos);
        else node->left = NULL;
        if (end > midpos+1) node->right = sortArray(nums, midpos+1, end);
        else node->right = NULL;
        return node;
    }
};

int main() {
    vector<int> nums({3,5,8});
    TreeNode* root = (new Solution())->sortedArrayToBST(nums);
    return 0;
}
