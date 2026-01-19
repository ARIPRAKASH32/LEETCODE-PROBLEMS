import java.util.*;
public class Leetcode457 {
    static class Solution {
        public boolean circularArrayLoop(int[] nums) {
            for (int i = 0; i < nums.length; i++) {
                float direction = Math.signum(nums[i]);
                int slow = i;
                int fast = i;
                do {
                    slow = getNextIndex(nums, direction, slow);
                    fast = getNextIndex(nums, direction, fast);
                    if (fast != -1)
                        fast = getNextIndex(nums, direction, fast);
                    if (fast == -1 || slow == -1 || nums[slow] == 0 || nums[fast] == 0)
                        break;
                } while (slow != fast);
                if (slow != -1 && slow == fast)
                    return true;
                nums[i] = 0;
            }
            return false;
        }
        private int getNextIndex(int[] nums, float direction, int i) {
            float currentDirection = Math.signum(nums[i]);
            if (currentDirection * direction < 0)
                return -1;
            int n = nums.length;
            int nextIndex = (i + nums[i]) % n;
            if (nextIndex < 0)
                nextIndex += n;
            return nextIndex == i ? -1 : nextIndex;
        }
    }
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] nums = new int[n];

        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();

        Solution sol = new Solution();
        System.out.println(sol.circularArrayLoop(nums));
    }
}
