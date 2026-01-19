class Solution {
    public int specialTriplets(int[] nums) {
        long mod = 1000000007;
        int n = nums.length;

        Map<Integer, Integer> left = new HashMap<>();
        Map<Integer, Integer> right = new HashMap<>();

        for (int x : nums) {
            right.put(x, right.getOrDefault(x, 0) + 1);
        }

        long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            right.put(x, right.get(x) - 1);

            long c1 = left.getOrDefault(2 * x, 0);  
            long c2 = right.getOrDefault(2 * x, 0);  

            ans = (ans + c1 * c2) % mod;

            left.put(x, left.getOrDefault(x, 0) + 1);
        }

        return (int)ans;
    }
}