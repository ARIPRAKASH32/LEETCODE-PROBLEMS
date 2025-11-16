from typing import List

class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:

        rows, cols = len(dungeon), len(dungeon[0])

        dp = [[0] * cols for _ in range(rows)]
        dp[-1][-1] = max(1, 1 - dungeon[-1][-1])

        for i in range(rows - 2, -1, -1):
            dp[i][-1] = max(1, dp[i + 1][-1] - dungeon[i][-1])

        for j in range(cols - 2, -1, -1):
            dp[-1][j] = max(1, dp[-1][j + 1] - dungeon[-1][j])

        for i in range(rows - 2, -1, -1):
            for j in range(cols - 2, -1, -1):
                min_health_needed = min(dp[i + 1][j], dp[i][j + 1])
                dp[i][j] = max(1, min_health_needed - dungeon[i][j])
        return dp[0][0]
