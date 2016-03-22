class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const size_t n = numbers.size();
        vector<int> res;
        int left, right, mid, sum;
        for(int i = 0; i < n; ++i){
            left = i + 1, right = n - 1;
            while(left <= right){
                mid = (left + right) / 2;
                sum = numbers[i] + numbers[mid];
                if(sum == target){
                    res.push_back(i + 1);
                    res.push_back(mid + 1);
                    return res;
                }else if(sum < target)
                    left = mid + 1;
                else right = mid - 1;
            }
        }
        return res;
    }
};
