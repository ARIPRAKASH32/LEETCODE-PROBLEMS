class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        vector<string> ans;
        for (int i = 0; i < words.size() - 2; i++) {
            if (words[i] == first && words[i + 1] == second) {
                ans.push_back(words[i + 2]);
            }
        }
        return ans;
    }
};
