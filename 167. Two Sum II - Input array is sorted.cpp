class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> res;
        while(left < right){
            long long val = numbers[left] + numbers[right];
            if(val == target){
                res.push_back(left + 1);
                res.push_back(right + 1);
                break;
            }else if(val < target)
                left++;
            else
                right--;
        }
        return res;
    }
};
