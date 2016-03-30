void minimalPathRec(TreeNode* root, vector<int> &path, int &total, vector<int> &res, int &sum){
	if(!root) return;
	path.push_back(root->val);
	total += root->val;
	if(!root->left && !root->right){
		if(total < sum){
			sum = total;
			res = path;
		}
		total -= root->val;
		path.pop_back();
		return;
	}
	minimalPathRec(root->left, path, total, res, sum);
	minimalPathRec(root->right, path, total, res, sum);
	total -= root->val;
	path.pop_back();
}
vector<int> minimalPath(TreeNode *root){
	vector<int> path, res;
	int sum = INT_MAX, total = 0;
	minimalPathRec(root, path, total, res, sum);
	return res;
}
