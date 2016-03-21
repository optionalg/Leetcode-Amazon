class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) 
            return false;
        vector<int> cnt(256, 0);
        for(int i = 0; i < s.length(); ++i){
            cnt[s[i]]++;
            cnt[t[i]]--;
        }
        for(int i = 0; i < cnt.size(); ++i)
            if(cnt[i] != 0) return false;
        return true;
    }
};
