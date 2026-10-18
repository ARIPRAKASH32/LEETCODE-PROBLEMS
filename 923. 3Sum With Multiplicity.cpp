class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long int ans=0;
        int n=arr.size();
        int mod=1e9+7;
        map<int,int>mpp;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<arr.size();j++) {
                int need=target-arr[i]-arr[j];
                ans+= mpp[need];
            }
            mpp[arr[i]]++;
        }
        return ans % mod;
    }
};
