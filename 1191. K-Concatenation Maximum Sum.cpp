# define ll long long
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        ll mod= 1000000007;
        if(k==1)
        {
            ll ans=0,sum=0;
            for(int i=0;i<arr.size();i++)
            {
                sum+=arr[i];
                sum%=mod;
                if(sum<0)
                {
                    ans=max(sum,ans);
                    sum=0;
                }
                ans=max(ans%mod,sum%mod);
                ans%=mod;
            }
            return ans % mod;
        }
        ll total=0;
        for(auto &i:arr)
        {
            total+=i;
            total%=mod;
        }
        total%=mod;
            vector<int>newarr=arr;
            int cnt=2;
            newarr.insert(newarr.end(),arr.begin(),arr.end());
            ll ans=0,sum=0;
            for(int i=0;i<newarr.size();i++)
            {
                sum+=newarr[i];
                ans=max(sum,ans);
                if(sum<0) sum=0;
            }
            ans%=mod;
            ll res= ans+(k-2)*total;
            return (total<0) ? ans%mod : res%mod;
        
        
            

    }
};
