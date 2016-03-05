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
    void dfs(TreeNode *root, int level, vector<vector<int>> &res){
        if(!root) return;
        if(res.size() <= level){
            vector<int> row;
            res.push_back(row);
        }
        res[level].push_back(root->val);
        dfs(root->left, level + 1, res);
        dfs(root->right, level + 1, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
};
