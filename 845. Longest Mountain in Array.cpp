class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;
        int len=1;
        bool climbing=true;
        if(arr.size()<3) return 0;
        for(int i=1;i<arr.size();i++){
            if(climbing==true&&arr[i]>arr[i-1]){
                len++;
            }
            else if(len>1&&arr[i]<arr[i-1]){
                climbing=false;
                len++;
                ans=max(ans,len);
            }
            else{
                climbing=true;
                if(arr[i]>arr[i-1]) len=2;
                else len=1;
            }
        }
         return ans;
    }
};
