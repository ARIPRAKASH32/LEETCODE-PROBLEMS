class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
      int n=arr.size();
      int ans=1;
      int len=1;
      int prev=0;

      for(int i=1;i<n;i++){
        int curr;
        if(arr[i-1]>arr[i])
        curr=1;

        else if(arr[i-1]<arr[i])
        curr=-1;
        
        else
        curr=0;

        if(curr==0)
        len=0;

        if(curr==-prev)
        len++;

        else
        len=2;

        ans=max(ans,len);

        prev=curr;
      }  
      return ans;
    }
};
