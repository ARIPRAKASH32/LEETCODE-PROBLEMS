class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        unordered_map<int,int>m;
        vector<vector<int>>v(labels.size(),vector<int>(2,0));
        for(int i=0;i<labels.size();i++){
            v[i][1]=labels[i];
            v[i][0]=values[i];
        }
        int sum=0;
        sort(v.rbegin(),v.rend());
        
        for(auto & e : v){
            if(numWanted>0){
            if(m[e[1]]<useLimit){
                sum=sum+e[0];
                numWanted--;
                m[e[1]]++;
            }
            }else{
                return  sum;
            }
        }
        return sum;
    }
};
