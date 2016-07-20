#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int INF = 0x3f3f3f3f;
    vector<int> s1;
    vector<int> s2;
    void preorder(TreeNode* node) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            s1.push_back(node->val);
            return; 
        }
        if (node->left)
            preorder(node->left);
        else 
            s1.push_back(INF);
        s1.push_back(node->val);
        if (node->right)
            preorder(node->right);
        else 
            s1.push_back(INF);
    }
    void postorder(TreeNode* node) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            s2.push_back(node->val);
            return; 
        }
        if (node->right)
            postorder(node->right);
        else 
            s2.push_back(INF);
        s2.push_back(node->val);
        if (node->left)
            postorder(node->left);
        else 
            s2.push_back(INF);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        TreeNode *lchild = root->left;
        TreeNode *rchild = root->right;
        preorder(lchild);
        postorder(rchild);
        if (s1.size() != s2.size()) {
            return false;
        }
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) 
                return false;
        }
        return true;
    }
};
