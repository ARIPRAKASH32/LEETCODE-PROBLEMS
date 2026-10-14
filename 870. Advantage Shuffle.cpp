class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
   sort(nums1.begin(),nums1.end());
   vector<pair<int,int>>temp;
   for(int i=0;i<nums2.size();i++){
    temp.push_back({nums2[i],i});
   }
   sort(temp.begin(),temp.end());
   vector<int>left;
   int i=0;
   int j=0;
   unordered_map<int,int>mpp;

   vector<int>ans;
   while(i<n&&j<m){
       if(nums1[i]>temp[j].first){
               mpp[temp[j].second]=nums1[i];
               i++;
               j++;
       }
       else{
         left.push_back(nums1[i]);
        i++;
       }
   }
   int l=0;
for(int i=0;i<n;i++){
    if(mpp.count(i)){
        ans.push_back(mpp[i]);
    }
    else{
        ans.push_back(left[l++]);
    }
}
return ans;
    }
};
