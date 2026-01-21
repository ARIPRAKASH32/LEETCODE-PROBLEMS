class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (nums == null || nums.length < 2 || k < 1 || t < 0) {
            return false;
        }
        HashMap<Long, Long> buckets = new HashMap<>();
        long bucketSize = (long) t + 1;
        for (int i=0; i<nums.length; i++) {
            if (i > k) {
                long lastBucket = ((long) nums[i - k - 1] - Integer.MIN_VALUE) / bucketSize;
                buckets.remove(lastBucket);
            }
            long reNum = (long) nums[i] - Integer.MIN_VALUE;
            long bucket = reNum / bucketSize;
            if (buckets.containsKey(bucket)) {
                return true;
            }
            if (buckets.containsKey(bucket - 1) && reNum - buckets.get(bucket - 1) <= t) {
                return true;
            }
            if (buckets.containsKey(bucket + 1) && buckets.get(bucket + 1) - reNum <= t) {
                return true;
            }
            buckets.put(bucket, reNum);
        }
        return false;
    }
}