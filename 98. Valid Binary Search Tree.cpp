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
    bool isValidBST(TreeNode* root, long min_val, long max_val){
        if(!root) return true;
        return min_val < root->val && root->val < max_val && 
               isValidBST(root->left, min_val, root->val) && isValidBST(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};
