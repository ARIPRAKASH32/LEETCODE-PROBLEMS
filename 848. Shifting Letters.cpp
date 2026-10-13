class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long maxi = 0;
        for (int i = shifts.size() - 1; i >= 0; i--) {
            maxi += shifts[i];
            s[i] = 'a' + (s[i] - 'a' + maxi) % 26;
        }return s;
    }
};
