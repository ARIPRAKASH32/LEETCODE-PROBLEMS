import java.util.*;

class Solution {
    public int[] closestRoom(int[][] rooms, int[][] queries) {

        int numRoom = rooms.length;
        int numQuery = queries.length;

        for (int i = 0; i < numQuery; i++) {
            queries[i] = new int[]{queries[i][0], queries[i][1], i};
        }

        Arrays.sort(rooms, (a, b) -> (a[1] != b[1] ? a[1] - b[1] : a[0] - b[0]));
        Arrays.sort(queries, (a, b) -> (a[1] != b[1] ? a[1] - b[1] : a[0] - b[0]));

        TreeSet<Integer> roomIds = new TreeSet<>();
        int[] result = new int[numQuery];

        int j = numRoom - 1;
        for (int i = numQuery - 1; i >= 0; i--) {

            int preferredId = queries[i][0];
            int minSize = queries[i][1];
            int queryIndex = queries[i][2];

            while (j >= 0 && rooms[j][1] >= minSize) {
                roomIds.add(rooms[j][0]);
                j--;
            }

            if (roomIds.isEmpty()) {
                result[queryIndex] = -1;
                continue;
            }

            if (roomIds.contains(preferredId)) {
                result[queryIndex] = preferredId;
                continue;
            }

            Integer higher = roomIds.higher(preferredId);
            Integer lower = roomIds.lower(preferredId);

            if (higher == null && lower == null) {
                result[queryIndex] = -1;
            } else if (higher == null) {
                result[queryIndex] = lower;
            } else if (lower == null) {
                result[queryIndex] = higher;
            } else {
                if (preferredId - lower <= higher - preferredId) {
                    result[queryIndex] = lower;
                } else {
                    result[queryIndex] = higher;
                }
            }
        }

        return result;
    }
}
