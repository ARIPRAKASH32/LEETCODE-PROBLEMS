class Solution {
    int lower, upper;
    public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length;
        long prefixSum[] = new long[n + 1];
        for (int i = 0; i < n; i++)
        prefixSum[i + 1] = prefixSum[i] + nums[i];
        long[] temp = new long[n + 1];
        this.lower = lower;
        this.upper = upper;
        return count(prefixSum, temp, 0, n);
    }
    public int count(long sum[], long temp[], int low, int high) {
        if (low >= high)
        return 0;
        int mid = high + low >> 1;
        int count = count(sum, temp, low, mid) + count(sum, temp, mid + 1, high);
        int index = 0;
        for (int i = low, j = mid + 1, k = mid + 1, l = mid + 1; i <= mid; i++) {
            long s = sum[i];
            while (j <= high && sum[j] - s < lower)
            j++;
            while (k <= high && sum[k] - s <= upper)
            k++;
            while (l <= high && sum[l] <= s)
            temp[index++] = sum[l++];
            temp[index++] = s;
            count += k - j;
        }
        System.arraycopy(temp, 0, sum, low, index);
        return count; 
    }
}