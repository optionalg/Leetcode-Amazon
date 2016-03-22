class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        if(strs.empty()) return res;
        sort(strs.begin(), strs.end());
        for(int i = 0; i < strs.size(); ++i){
            string temp = strs[i];
            if(!temp.empty())
                sort(temp.begin(), temp.end());
            map[temp].push_back(strs[i]);
        }
        for(unordered_map<string, vector<string>>::iterator it = map.begin(); it != map.end(); ++it)
            res.push_back(it->second);
        return res;
    }
};
