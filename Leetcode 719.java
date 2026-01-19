class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int minDistance = 0;
        int maxDistance = nums[nums.length - 1] - nums[0];
        while (minDistance < maxDistance) {
            int midDistance = minDistance + (maxDistance - minDistance) / 2;
            int pairsCount = countPairsWithinDistance(nums, midDistance);
            
            if (pairsCount < k) {
                minDistance = midDistance + 1;
            } else {
                maxDistance = midDistance;
            }
        }
        return minDistance;
    }
    private int countPairsWithinDistance(int[] nums, int targetDistance) {
        int count = 0;
        int left = 0;
        for (int right = 1; right < nums.length; right++) {
            while (nums[right] - nums[left] > targetDistance) {
                left++;
            }
            count += right - left;
        }
        return count;
    }
}