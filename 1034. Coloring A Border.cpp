#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, int curr, vector<vector<int>>& grid, vector<vector<int>>& isvisited, vector<pair<int, int>>& border) {
        int m = grid.size();
        int n = grid[0].size();
        isvisited[row][col] = 1;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        bool isBorder = false;
        for (int k = 0; k < 4; k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) isBorder = true;
            else if (grid[nr][nc] != curr) isBorder = true;
            else if (!isvisited[nr][nc]) dfs(nr, nc, curr, grid, isvisited, border);
        }
        if (isBorder) {
            border.push_back({row, col});
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> isvisited(m, vector<int>(n, 0));
        vector<pair<int, int>> border;
        int curr = grid[row][col];
        dfs(row, col, curr, grid, isvisited, border);
        for (auto& p : border) {
            grid[p.first][p.second] = color;
        }
        return grid;
    }
};
