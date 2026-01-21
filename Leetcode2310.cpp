class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        k = k % n;   // handle large k

        string ss = "";
        for (int i = k; i < n; i++) {
            ss += s[i];
        }
        for (int i = 0; i < k; i++) {
            ss += s[i];
        }
        return ss;
    }
};
