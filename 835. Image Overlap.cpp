class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int n=img1.size();
        bitset<30> B1[n], B2[n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                B1[i][j]=img1[i][j];
                B2[i][j]=img2[i][j];
            }
        
        int ans=0;
        for(int i=-n+1; i<n; i++){
            for(int j=-n+1; j<n; j++){ 
                int cnt=0;
                for(int k=0; k<n; k++){
                    int k1=k+i;
                    if (k1<0 || k1>=n) continue;
                    auto sB=(j<0)?B1[k1]<<(-j):B1[k1]>>j;
                    cnt+=(sB & B2[k]).count();
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
};
