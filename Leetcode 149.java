import java.util.HashMap;
import java.util.Map;

public class Leetcode149 {
    public int maxPoints(int[][] points) {
        if (points == null) return 0;
        if (points.length <= 2) return points.length;

        int result = 0;

        for (int i = 0; i < points.length; i++) {
            Map<Integer, Map<Integer, Integer>> map = new HashMap<>();
            int overlap = 0;
            int max = 0;

            for (int j = i + 1; j < points.length; j++) {
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];

                if (x == 0 && y == 0) {
                    overlap++;
                    continue;
                }

                int gcd = generateGCD(x, y);
                x /= gcd;
                y /= gcd;

                map.putIfAbsent(x, new HashMap<>());
                Map<Integer, Integer> inner = map.get(x);

                inner.put(y, inner.getOrDefault(y, 0) + 1);
                max = Math.max(max, inner.get(y));
            }

            result = Math.max(result, max + overlap + 1);
        }

        return result;
    }

    private int generateGCD(int a, int b) {
        if (b == 0) return a;
        return generateGCD(b, a % b);
    }
}
