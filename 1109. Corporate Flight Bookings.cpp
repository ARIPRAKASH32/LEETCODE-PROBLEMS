class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int>ans(n);

        for(auto ele:bookings){

            int start=ele[0]-1;
            int end=ele[1];
            int seat=ele[2];

            ans[start]+=seat;
            if(end<n) ans[end]-=seat;

        }

        for(int i=1;i<n;i++){
            ans[i]+=ans[i-1];
        }

        return ans;
    }
};
