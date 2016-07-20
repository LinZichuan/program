/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        pair<int,int> res = dfs(root);
        return max(res.first, res.second);
    }
    /*
     * store maxleft[2] and maxright[2], maxleft[0] is value without robbing left house, maxleft[1] is value with robbing left house.
    */
    pair<int,int> dfs(TreeNode *node) {
        if (!node) return make_pair(0,0);
        pair<int,int> maxleft  = dfs(node->left);
        pair<int,int> maxright = dfs(node->right);
        pair<int,int> maxval;
        maxval.first = max(maxleft.first, maxleft.second) + max(maxright.first, maxright.second); //Important!: select the maxvalue of maxleft[2], as well as maxright[2].
        maxval.second = maxleft.first + maxright.first + node->val;
        return maxval;
    }
};
