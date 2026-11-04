class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> seen;
        int score = 0, res = 0;
        for (int i = 0, n = hours.size(); i < n; ++i) {
            if(hours[i] > 8) ++score;
            else --score;
            if (score > 0) res = i + 1;
            else if (seen.count(score - 1)) res = max(res, i - seen[score - 1]);
            if (!seen.count(score)) seen[score] = i;
        }
        return res;
    }
};
