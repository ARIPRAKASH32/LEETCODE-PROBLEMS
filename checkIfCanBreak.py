class Solution(object):
    def checkIfCanBreak(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        
        s1 = sorted(s1)
        s2 = sorted(s2)
        i=0
        while i<len(s1):
            if s1[i] > s2[i]:
                flg = 1
                break
            elif s2[i]>s1[i]:
                flg = 2
                break
            i+=1
        
        sr = s1 if flg == 1 else s2
        srr = s2 if flg == 1 else s1
        
        fl = 0
        for i in range(len(s1)):
            if sr[i] < srr[i]:
                fl = 1
                break
        
        if fl == 0: 
            return True
        else:
            return False
