class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (auto it : s) {
            freq[it - 'a']++;
        }

        string prefix = "";
        bool fullyMatched = false;
        for (int i = 0; i < (int)target.length(); i++) {
            if (freq[target[i] - 'a'] == 0) break;
            freq[target[i] - 'a']--;
            prefix += target[i];
            if (i == target.length() - 1) {
                fullyMatched = true;
                break;
            }
        }

        if (!fullyMatched && prefix.length() < target.length()) {
            int pos = prefix.length();
            int x = target[pos] - 'a';
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] == 0) continue;
                string ans = prefix;
                ans += char(c + 'a');
                freq[c]--;
                for (int j = 0; j < 26; j++) {
                    ans.append(freq[j], char(j + 'a'));
                }
                return ans;
            }
        }

        for (int i = prefix.length() - 1; i >= 0; i--) {
            freq[prefix[i] - 'a']++;
            char ch = prefix[i];
            prefix.pop_back();
            for (int c = ch - 'a' + 1; c < 26; c++) {
                if (freq[c] == 0) continue;
                string ans = prefix;
                ans += char(c + 'a');
                freq[c]--;
                for (int j = 0; j < 26; j++) {
                    ans.append(freq[j], char(j + 'a'));
                }
                return ans;
            }
        }
        return "";
    }
};
