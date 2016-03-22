class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
    	const size_t n = nums.size();
    	if(n == 0) return res;
    	sort(nums.begin(), nums.end());
    	unsigned long long maxNum = pow(2, n);
    	for(unsigned long long i = 0; i < maxNum; ++i){
    		subset.clear();
    		for(int j = 0; j < n; ++j)
    			if((i >> j) & 1 != 0 )
    				subset.push_back(nums[j]);
    		res.push_back(subset);
    	}
    	return res;
    }
};
