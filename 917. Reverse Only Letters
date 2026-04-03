class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (isalpha(s[start]) && isalpha(s[end])) {
                swap(s[start], s[end]);
                start++;
                end--;
            } else if (!isalpha(s[start])) {
                start++;
            } else {
                end--;
            }
        }
        return s;
    }
};
