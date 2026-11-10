class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int l=0,cost=0, ans=0;
        for (int r=0;r<n;r++) {
            cost+=abs(t[r]-s[r]);
            while(cost>maxCost) {
                cost-=abs(t[l]-s[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
