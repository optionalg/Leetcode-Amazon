class Solution {
public:
    void reverse(int begin, int end, string &s){
        while(begin < end)
            swap(s[begin++], s[end--]);
    }
    void reverseWords(string &s) {
        const size_t n = s.length();
        reverse(0, n - 1, s);
        int i, j;
        for(i = 0, j = 0; j <= n; ++j){
            if(j == n || s[j] == ' '){
                reverse(i, j - 1, s);
                i = j + 1;
            }
        }
    }
};
