class Solution {
public:
    int freqOfSmallestChar(string s) {
        vector<int> freq(26, 0);
        for (auto ch : s)
            freq[ch - 'a']++;
        for (auto f : freq)
            if (f != 0)
                return f;
        return -1;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries,
                                      vector<string>& words) {
        vector<int> ans(queries.size(), 0);
        vector<int> wordFreq;
        for (const auto& word : words)
            wordFreq.push_back(freqOfSmallestChar(word));
        sort(wordFreq.begin(), wordFreq.end());
        for (int i = 0; i < queries.size(); i++) {
            int f = freqOfSmallestChar(queries[i]);
            int left = 0, right = wordFreq.size() - 1;
            int index = wordFreq.size();
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (wordFreq[mid] > f) {
                    index = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans[i] = wordFreq.size() - index;
        }
        return ans;
    }
};
