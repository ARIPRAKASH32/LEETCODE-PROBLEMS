class Solution {
public:
    bool isPossibleDivide(vector<int>& arr, int k) {
        int n=arr.size();
        if (n%k!=0){
            return 0;
        }
        map<int,int> mp;
        for (int i=0 ; i<n ; i++){
            mp[arr[i]]++;
        }
        for (auto &i : mp){
            int x=i.first , y=i.second;
            if (y!=0){
                for (int j=x ; j<x+k ; j++){
                    if (mp[j]<y){
                        return 0;
                    }
                    mp[j]-=y;
                }
            }
        }
        return 1;
    }
};
