import java.util.*;

public class Main {

    static class Solution {

        public int minAbsDifference(int[] nums, int goal) {

            int[] part1 = new int[nums.length / 2];
            int[] part2 = new int[nums.length - part1.length];

            int k = 0;
            for (int i = 0; i < part1.length; i++) {
                part1[i] = nums[i];
                k++;
            }
            for (int i = 0; i < part2.length; i++) {
                part2[i] = nums[k];
                k++;
            }

            ArrayList<Integer> sum1 = new ArrayList<>();
            ArrayList<Integer> sum2 = new ArrayList<>();

            addSum(sum1, part1, 0, 0);
            addSum(sum2, part2, 0, 0);

            Collections.sort(sum1);
            Collections.sort(sum2);

            int low = 0;
            int high = sum2.size() - 1;
            int res = Integer.MAX_VALUE;

            while (low < sum1.size() && high >= 0) {
                int sum = sum1.get(low) + sum2.get(high);
                res = Math.min(res, Math.abs(sum - goal));

                if (sum > goal) {
                    high--;
                } else if (sum == goal) {
                    return 0;
                } else {
                    low++;
                }
            }
            return res;
        }

        private void addSum(ArrayList<Integer> sumlist, int[] part, int sum, int si) {
            if (si >= part.length) {
                sumlist.add(sum);
                return;
            }
            addSum(sumlist, part, sum + part[si], si + 1);
            addSum(sumlist, part, sum, si + 1);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] nums = new int[n];

        for (int i = 0; i < n; i++)
            nums[i] = sc.nextIn
