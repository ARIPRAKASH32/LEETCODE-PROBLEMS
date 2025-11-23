class Solution(object):
    def sumAndMultiply(self, n):
        """
        :type n: int
        :rtype: int
        """
        x=int("".join(c  for c in str(n) if c != '0') or "0")
        s= sum(map(int,str(x)))
        return x*s
