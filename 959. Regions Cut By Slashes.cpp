#define pp pair<int,int>

class Solution {
public:
    void bfs(int r, int c, vector<vector<int>>& grid) {
        int req = grid.size();
        queue<pp> q;
        q.push({r, c});
        grid[r][c] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < req && nc < req) {
                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    int regionsBySlashes(vector<string>& gr) {
        int n = gr.size();
        int req = 3 * n;
        vector<vector<int>> grid(req, vector<int>(req, 0));

        // Expand each cell to a 3x3 block
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ii = i * 3;
                int jj = j * 3;

                if (gr[i][j] == '/') {
                    grid[ii][jj + 2]     = 1;
                    grid[ii + 1][jj + 1] = 1;
                    grid[ii + 2][jj]     = 1;
                }
                if (gr[i][j] == '\\') {
                    grid[ii][jj]         = 1;
                    grid[ii + 1][jj + 1] = 1;
                    grid[ii + 2][jj + 2] = 1;
                }
            }
        }

        // Count connected components of 0s
        int count = 0;
        for (int i = 0; i < req; i++) {
            for (int j = 0; j < req; j++) {
                if (grid[i][j] == 0) {
                    bfs(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }
};
