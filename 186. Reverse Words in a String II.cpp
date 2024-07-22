class Solution {
public:
    void reverseWords(vector<char>& s) {
        // Step 1: Reverse the entire character array
        reverse(s.begin(), s.end());

        // Step 2: Reverse each word in the reversed array
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        // Reverse the last word
        reverse(s.begin() + start, s.end());
    }

    void reverse(vector<char>& s, int i, int j) {
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
