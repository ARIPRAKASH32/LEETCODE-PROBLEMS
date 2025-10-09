import java.util.*;

class FindMin {
    public long minTime(int[] skill, int[] mana) {
        int n = skill.length;
        long[] time = new long[n];
        for (int x : mana) {
            time[0] = time[0] + 1L * skill[0] * x;
            for (int i = 1; i < n; i++) {
                time[i] = Math.max(time[i], time[i - 1]) + 1L * skill[i] * x;
            }
            for (int i = n - 2; i >= 0; i--) {
                time[i] = time[i + 1] - 1L * skill[i + 1] * x;
            }
        }
        return time[n - 1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] skill = new int[n];
        for (int i = 0; i < n; i++) skill[i] = sc.nextInt();
        int m = sc.nextInt();
        int[] mana = new int[m];
        for (int i = 0; i < m; i++) mana[i] = sc.nextInt();
        FindMin sol = new FindMin();
        System.out.println(sol.minTime(skill, mana));
        sc.close();
    }
}

