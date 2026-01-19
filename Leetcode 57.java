import java.util.*;

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {

        List<int[]> intervalList = new ArrayList<>(Arrays.asList(intervals));
        intervalList.add(newInterval);
        Collections.sort(intervalList, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> res = new ArrayList<>();
        int[] current = intervalList.get(0);

        for (int i = 1; i < intervalList.size(); i++) {
            int[] interval = intervalList.get(i);

            if (current[1] >= interval[0]) {
                current[1] = Math.max(current[1], interval[1]);
            } else {
                res.add(current);
                current = interval;
            }
        }

        res.add(current);
        return res.toArray(new int[res.size()][]);
    }
}

public class Leetcode57 {
    public static void main(String[] args) {

        Solution sol = new Solution();

        int[][] intervals = {
            {1, 3},
            {6, 9}
        };

        int[] newInterval = {2, 5};

        int[][] result = sol.insert(intervals, newInterval);

        for (int[] arr : result) {
            System.out.println(Arrays.toString(arr));
        }
    }
}
