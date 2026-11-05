class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> up(n, vector<int>(m, 0));
        vector<vector<int>> left(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1) {
                    up[i][j] = (i>0) ? up[i-1][j]+1: 1;
                    left[i][j] = (j>0) ? left[i][j-1]+1 : 1;
                    int len = min(up[i][j], left[i][j]);
                    while(len>cnt) {
                        if(up[i][j-len+1]>=len && left[i-len+1][j]>=len) {
                            cnt = len;
                        }
                        len--;
                    } 
                }
            }
        }
        return cnt*cnt;
    }
};
