class Solution {
public:
    void subsetRec(int i, const vector<int> &nums, vector<int> &subset, vector<vector<int>> &res){
        res.push_back(subset);
        for(int j = i; j < nums.size(); ++j){
            subset.push_back(nums[j]);
            subsetRec(j + 1, nums, subset, res);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        if(nums.empty()) return res;
        sort(nums.begin(), nums.end());
        subsetRec(0, nums, subset, res);
        return res;
    }
};
