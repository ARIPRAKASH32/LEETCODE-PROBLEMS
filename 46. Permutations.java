import java.util.*;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums.length == 1) {
            List<Integer> singleList = new ArrayList<>();
            singleList.add(nums[0]);
            res.add(singleList);
            return res;
        }

        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            int[] remainingNums = new int[nums.length - 1];
            int index = 0;

            for (int j = 0; j < nums.length; j++) {
                if (j != i) {
                    remainingNums[index++] = nums[j];
                }
            }

            List<List<Integer>> perms = permute(remainingNums);
            for (List<Integer> p : perms) {
                p.add(n);
            }

            res.addAll(perms);
        }

        return res;        
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        Solution obj = new Solution();
        List<List<Integer>> result = obj.permute(nums);

        for (List<Integer> perm : result) {
            System.out.println(perm);
        }
    }
}

