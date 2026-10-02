class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) 
    {
        vector<vector<int>> grid(n,vector<int>(n,1));
        for(auto i:mines) grid[i[0]][i[1]]=0;
        vector<vector<vector<int>>> v(n,vector<vector<int>>(n,vector<int>(4,0)));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0) v[i][j][0]=grid[i][j];
                else if(grid[i][j]==1) v[i][j][0]=1+v[i-1][j][0];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(i==n-1) v[i][j][1]=grid[i][j];
                else if(grid[i][j]==1) v[i][j][1]=1+v[i+1][j][1];
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(j==0) v[i][j][2]=grid[i][j];
                else if(grid[i][j]==1) v[i][j][2]=1+v[i][j-1][2];
            }
        }
        for(int j=n-1;j>=0;j--)
        {
            for(int i=0;i<n;i++)
            {
                if(j==n-1) v[i][j][3]=grid[i][j];
                else if(grid[i][j]==1) v[i][j][3]=1+v[i][j+1][3];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,min(v[i][j][0],min(v[i][j][1],min(v[i][j][2],v[i][j][3]))));
            }
        }
        return ans;
    }
};
