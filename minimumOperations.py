class Solution(object):
    def minimumOperations(self, nums):
        count=0
        for i in nums:
            if i%3!=0:
                count=count+1
        return count
        """
        :type nums: List[int]
        :rtype: int
        """
        
