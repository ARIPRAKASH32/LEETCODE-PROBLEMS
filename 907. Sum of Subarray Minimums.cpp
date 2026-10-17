class Solution {
public:
    int M = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+2, 0);
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < n; i++){
            while(st.top() > -1 && arr[st.top()] > arr[i]) st.pop();
            int till = st.top();
            int before = dp[till+2] - dp[till+1];
            dp[i+2] = ( dp[i+1] + (1LL * (i-till) * arr[i]) + before + M )%M;
            st.push(i);
        }

        return dp[n+1];
    }
};
