class Solution {
public:
    string longestPalindrome(string s) {
        const size_t n = s.length();
        int max_len = 0, start = 0;
        bool isPalindrome[1000][1000] = {false};
        for(int len = 1; len <= n; ++len){
            for(int i = 0, j; i < n - len + 1; ++i){
                j = i + len - 1;
                if(len == 1) isPalindrome[i][j] = true;
                else if(len == 2) isPalindrome[i][j] = (s[i] == s[j]);
                else if(s[i] == s[j] && isPalindrome[i + 1][j - 1])
                    isPalindrome[i][j] = true;
                if(isPalindrome[i][j] && len > max_len){
                    max_len = len;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);
        
    }
};
