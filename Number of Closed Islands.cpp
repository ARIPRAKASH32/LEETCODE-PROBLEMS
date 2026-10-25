class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() ||
            j >= grid[0].size() || grid[i][j] == 1)
            return;

        int stps[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        grid[i][j] = 1;

        for (auto& k : stps) {
            dfs(grid, i + k[0], j + k[1]);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            dfs(grid, i, 0);
            dfs(grid, i, grid[0].size() - 1);
        }

        for (int j = 0; j < grid[0].size(); j++) {
            dfs(grid, 0, j);
            dfs(grid, grid.size() - 1, j);
        }

        int c = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    c++;
                    dfs(grid, i, j);
                }
            }
        }

        return c;
    }
};
