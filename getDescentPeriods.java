public class Solution {

    public static long getDescentPeriods(int[] prices) {
        long sum = 0;
        long des = 0;
        int prev = -1;

        for (int x : prices) {
            des = (x + 1 == prev) ? des + 1 : 1;
            sum += des;
            prev = x;
        }
        return sum;
    }

    public static void main(String[] args) {
        int[] prices = {3, 2, 1, 4};
        System.

