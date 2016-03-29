class Solution {
public:
    string expand(const string &s, int left, int right){
        const size_t n = s.length();
        while(left >= 0 && right < n && s[left] == s[right]) left--, right++;
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        const size_t n = s.length();
        if(n == 0) return "";
        string res = s.substr(0, 1), temp;
        for(int i = 0; i < n - 1; ++i){
            temp = expand(s, i, i);
            if(temp.length() > res.length()) res = temp;
            temp = expand(s, i, i + 1);
            if(temp.length() > res.length()) res = temp;
        }
        return res;
    }
};
