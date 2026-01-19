class Solution {
    public int countPartitions(int[] nums, int k) {
        int n = nums.length;
        final long MOD = 1_000_000_007L;

        long[] dp = new long[n + 1];
        long[] prefix = new long[n + 1]; 
        dp[0] = 1;
        prefix[0] = dp[0];

        Deque<Integer> maxQ = new ArrayDeque<>();
        Deque<Integer> minQ = new ArrayDeque<>();
        int left = 0; 
        for (int i = 1; i <= n; i++) {
            int idx = i - 1; 
            while (!maxQ.isEmpty() && nums[maxQ.peekLast()] < nums[idx]) {
                maxQ.pollLast();
            }
            maxQ.addLast(idx);
            while (!minQ.isEmpty() && nums[minQ.peekLast()] > nums[idx]) {
                minQ.pollLast();
            }
            minQ.addLast(idx);
            while (!maxQ.isEmpty() && !minQ.isEmpty() &&
                   nums[maxQ.peekFirst()] - nums[minQ.peekFirst()] > k) {
                if (maxQ.peekFirst() == left) maxQ.pollFirst();
                if (minQ.peekFirst() == left) minQ.pollFirst();
                left++;
            }

            long sum;
            if (left > 0) sum = (prefix[i - 1] - prefix[left - 1] + MOD) % MOD;
            else sum = prefix[i - 1];

            dp[i] = sum % MOD;
            prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
        }

        return (int) dp[n];
    }
}