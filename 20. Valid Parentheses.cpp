class Solution {
public:
    unordered_map<char, char> map = {{')','('}, {']', '['}, {'}', '{'}};
    bool isValid(string s) {
        vector<char> stack;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                stack.push_back(s[i]);
            else if(!stack.empty() && map[s[i]] == stack.back())
                stack.pop_back();
            else return false;
        }
        return stack.empty();
    }
};
