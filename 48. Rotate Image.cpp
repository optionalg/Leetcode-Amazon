class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        const size_t n = matrix.size(), m = matrix[0].size();
        //transpose
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
        int left = 0, right = m - 1;
        //swap left and right column
        while(left < right){
            for(int i = 0; i < n; ++i)
                swap(matrix[i][left], matrix[i][right]);
            left++, right--;
        }
    }
};
