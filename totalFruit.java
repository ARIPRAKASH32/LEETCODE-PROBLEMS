class Solution {
    public int totalFruit(int[] fruits) {
        int max = 0;
        Map<Integer, Integer> baskets = new HashMap<>();

        for (int left = 0, right = 0; left < fruits.length && right < fruits.length; ++right) {
            baskets.put(fruits[right], baskets.getOrDefault(fruits[right], 0) + 1);

            if (baskets.size() > 2)
                moveLeftBorder(baskets, fruits[left++]);
            else
                max = Math.max(right - left + 1, max);
        }

        return max;
    }

    private void moveLeftBorder(Map<Integer, Integer> baskets, int typeToDecrease) {
        baskets.put(typeToDecrease, baskets.get(typeToDecrease) - 1);
        if (baskets.get(typeToDecrease) == 0)
            baskets.remove(typeToDecrease);
    }
}
