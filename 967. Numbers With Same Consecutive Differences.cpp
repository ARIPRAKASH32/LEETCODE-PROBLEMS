class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        queue<int> q;
        for(int i=1; i<10; i++) q.push(i);

        while(!q.empty()) {
            int x = q.front();
            q.pop();
            if(to_string(x).size() == n) {
                ans.push_back(x); continue;
            }
            for(int i=0; i<10; i++) {
                if(abs((x % 10) - i) == k) q.push(x*10 + i);
            }
        }

        return ans;
    }
};
