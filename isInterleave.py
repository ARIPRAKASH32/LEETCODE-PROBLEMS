class isInterleave:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        if len(s3) != m + n:
            return False

        def dp(i, j, memo: dict):
            if i == m and j == n:
                return True
            if (i, j) not in memo:
                memo[(i, j)] = (
                    (i < m and s1[i] == s3[i+j] and dp(i+1, j, memo)) or
                    (j < n and s2[j] == s3[i+j]) and dp(i, j+1, memo)
                )
            return memo[(i, j)]
        return dp(0, 0, {})
