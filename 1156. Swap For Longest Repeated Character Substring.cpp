class Solution {
public:
    int maxRepOpt1(string text) 
    {
        int ans=0, hash[26] = {0};
        for(char ch: text) ++hash[ch-'a'];

        for(char ch='a'; ch<='z'; ch++)
        {
            int curr=0, other=0, l=0;
            for(int r=0; r<text.size(); r++)
            {
                if(text[r] == ch) ++curr;
                else ++other;

                while(l<=r and other > 1)
                {
                    if(text[l++] == ch) --curr;
                    else --other;
                }

                ans = max(ans, min(curr + other, hash[ch-'a']));
            }
        }

        return ans;
    }
};
