class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        return sum(len(set(s[s.find(c)+1:s.rfind(c)])) for c in set(s) if s.count(c) > 1)

