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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        int curLevelCnt = 1, nextLevelCnt = 0, visitedCnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        while(!q.empty()){
            cur = q.front(), q.pop();
            visitedCnt++;
            if(cur->left){
                nextLevelCnt++;
                q.push(cur->left);
            }
            if(cur->right){
                nextLevelCnt++;
                q.push(cur->right);
            }
            if(curLevelCnt == visitedCnt){
                res.push_back(cur->val);
                curLevelCnt = nextLevelCnt;
                nextLevelCnt = 0;
                visitedCnt= 0;
            }
        }
        return res;
    }
};
