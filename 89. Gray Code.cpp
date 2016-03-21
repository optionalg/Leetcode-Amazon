class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for(int i = 1, scale = 1; i <= n; ++i, scale *= 2){
            for(int j = res.size() - 1; j >= 0; --j)
                res.push_back(res[j] + scale);
        }
        return res;
    }
};
