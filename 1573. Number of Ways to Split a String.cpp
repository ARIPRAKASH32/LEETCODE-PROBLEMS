class Solution {
    public int numWays(String s) {
        final long MOD = 1_000_000_007L;

        int total = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') total++;
        }

        if (total % 3 != 0) return 0;
        if (total == 0) {
            long n = s.length();
            return (int) (((n - 1) * (n - 2) / 2) % MOD);
        }

        int each = total / 3;
        int ones = 0;

        long firstChoices = 0;
        long secondChoices = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                ones++;

                if (ones == each) {
                    firstChoices = 1;

                    int j = i + 1;
                    while (j < s.length() && s.charAt(j) == '0') {
                        firstChoices++;
                        j++;
                    }
                }

                if (ones == 2 * each) {
                    secondChoices = 1;

                    int j = i + 1;
                    while (j < s.length() && s.charAt(j) == '0') {
                        secondChoices++;
                        j++;
                    }

                    break;
                }
            }
        }

        return (int) ((firstChoices * secondChoices) % MOD);
    }
}
