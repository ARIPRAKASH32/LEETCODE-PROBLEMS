class Solution {
public:
    int flipgame(vector<int>& front, vector<int>& back) 
    {
        int n = front.size(), ans = INT_MAX;
        unordered_map<int, int> um;
        for(int i = 0; i < n; i++)
        {
            if(front[i] == back[i])
                um[front[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            if(!um.count(front[i]))
            {
                ans = min(ans, front[i]);
                um[front[i]]++;
            }
            if(!um.count(back[i]))
            {
                ans = min(ans, back[i]);
                um[back[i]]++;
            }
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};
