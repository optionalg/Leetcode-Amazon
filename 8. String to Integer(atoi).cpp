class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int end = str.find_first_not_of(' ', 0);
        if(end == str.length() || (str[end] != '+' && str[end] != '-' && !isdigit(str[end]))) 
            return 0;
        int sign = str[end] == '-' ? -1 : 1;
        if(!isdigit(str[end])) end++;
        while(isdigit(str[end])){
            res = res * 10 + (str[end++] - '0') * sign;
            if(res >= INT_MAX) return INT_MAX;
            else if(res <= INT_MIN) return INT_MIN;
        }
        return res;
    }
};
