class Solution {
public:
    string findReplaceString(string s, vector<int>& indices,
                             vector<string>& sources, vector<string>& targets) {

        unordered_map<int, int> match;

        // Validate replacements
        for (int i = 0; i < indices.size(); i++) {
            if (s.compare(indices[i], sources[i].size(), sources[i]) == 0) {
                match[indices[i]] = i;
            }
        }

        // Apply replacements from right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            if (match.contains(i)) {
                s.replace(i, sources[match[i]].size(), targets[match[i]]);
            }
        }

        return s;
    }
};
