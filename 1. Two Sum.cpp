class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        return a.first < b.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pairs;
        for(int i = 0; i < nums.size(); ++i)
            pairs.push_back(make_pair(nums[i], i));
        sort(pairs.begin(), pairs.end(), cmp);
        int left = 0, right = pairs.size() - 1, sum;
        vector<int> res;
        while(left < right){
            sum = pairs[left].first + pairs[right].first;
            if(sum < target) left++;
            else if(sum > target) right--;
            else{
                res.push_back(pairs[left].second);
                res.push_back(pairs[right].second);
                if(pairs[left].second > pairs[right].second)
                    reverse(res.begin(), res.end());
                return res;
            }
        }
        return res;
    }
};
