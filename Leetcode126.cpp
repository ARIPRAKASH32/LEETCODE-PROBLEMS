class Solution {
public:
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> dist;
    vector<vector<string>> ans;

    void bfs(string beginWord, string endWord, unordered_set<string>& dict) {
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = dist[word];

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (!dict.count(temp)) continue;

                    if (!dist.count(temp)) {
                        dist[temp] = steps + 1;
                        q.push(temp);
                        parent[temp].push_back(word);
                    }
                    else if (dist[temp] == steps + 1) {
                        parent[temp].push_back(word);
                    }
                }
            }
        }
    }
    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto &p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        bfs(beginWord, endWord, dict);

        if (!dist.count(endWord)) return {};

        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, path);

        return ans;
    }
};