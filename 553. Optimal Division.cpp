class Solution {
public:
    string optimalDivision(vector<int>& nums) {
       int n=nums.size();
       if(n==1)
       {
        string ans=to_string(nums[0]);
        return ans;
       }
       if(n==2)
       {
          string ans="";
           ans=to_string(nums[0]);
           ans.push_back('/');
           ans=ans+to_string(nums[1]);
          return ans;
       } 
       string ans="";
       ans=ans+to_string(nums[0]);
       ans.push_back('/');
       ans.push_back('(');
       ans=ans+to_string(nums[1]);
       for(int i=2;i<n;i++)
       {
        ans.push_back('/');
        ans=ans+to_string(nums[i]);
       }
       ans.push_back(')');
       return ans;
    }
};
