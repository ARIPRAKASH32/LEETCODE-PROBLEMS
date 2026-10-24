class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int cost = 0;
        map<int, int> d;
        for (auto x : days)
            d[x] = 1;

        vector<int> dp(366, 0);   
        for (int i = 1; i < 366; i++)
        {
            if (d.count(i) == 1)
            {
                
                dp[i] = INT_MAX;
                if (i - 1 >= 0)
                {
                    dp[i] = dp[i - 1] + costs[0];
                }
                if (i - 7 >= 0)
                {
                    dp[i] = min(dp[i], dp[i - 7] + costs[1]);
                }
                else
                {
                    dp[i] = min(dp[i], costs[1]);
                }
                if (i - 30 >= 0)
                {
                    dp[i] = min(dp[i], dp[i - 30] + costs[2]);
                }
                else
                {
                    dp[i] = min(dp[i], costs[2]);
                }
            }
            else
            dp[i]=dp[i-1];
        }

        return dp[365];
    }
};
