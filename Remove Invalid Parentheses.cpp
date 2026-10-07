class Solution {
    vector<string> ans;

    void dfs(string s, int start, int last,
             char open, char close) {

        int balance = 0;

        for (int i = start; i < s.size(); i++) {
            if (s[i] == open) balance++;
            if (s[i] == close) balance--;

            if (balance >= 0) continue;

            for (int j = last; j <= i; j++) {
                if (s[j] == close &&
                    (j == last || s[j - 1] != close)) {

                    dfs(
                        s.substr(0, j) + s.substr(j + 1),
                        i,
                        j,
                        open,
                        close
                    );
                }
            }

            return;
        }

        reverse(s.begin(), s.end());

        if (open == '(') {
            dfs(s, 0, 0, ')', '(');
        } else {
            ans.push_back(s);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        dfs(s, 0, 0, '(', ')');
        return ans;
    }
};
