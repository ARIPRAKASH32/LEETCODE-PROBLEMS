class Solution {
public:
    int findSubstringInWraproundString(string s) {
        
          int n = s.size();
        // difference array
         vector<int>diff(n,0);
 for (int i = 1; i < n; i++) {
            int currentDiff = s[i] - s[i - 1];
            
            // Handle wraparound for 'z' to 'a'
            if (currentDiff == 1 || (s[i - 1] == 'z' && s[i] == 'a')) {
                diff[i] = 1;
            }
        }

        // Hash array
        vector<int>hash(26,0);

        int i=0,j=0;
        int count = 0 ,ans =0;
        while(j < n)
        {
            if(diff[j] !=1)
            {
              count=1;
            //   ans +=count;
              i=j;
            }
            else
            {
               count = j-i+1;
            //    ans +=count;
            }

            if(hash[s[j]-'a'] < count)
            {
                hash[s[j]-'a'] = count;
            }
            j++;
        }
        
        int sum = accumulate(hash.begin(),hash.end(),0);
        return sum;
}
};
