class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        String[] result = new String[n];
        if (n == 1) {
            result[0] = "Gold Medal";
            return result;
        }
        if (n == 2) {
            if (score[0] > score[1]) {
                result[0] = "Gold Medal";
                result[1] = "Silver Medal";
            } else {
                result[1] = "Gold Medal";
                result[0] = "Silver Medal";
            }
            return result;
        }
        int[] scoresCopy = score.clone();
        Arrays.sort(scoresCopy);
        Map<Integer, String> map = new HashMap<>();
        map.put(scoresCopy[n - 1], "Gold Medal");
        map.put(scoresCopy[n - 2], "Silver Medal");
        map.put(scoresCopy[n - 3], "Bronze Medal");
        for (int i = n - 4; i >= 0; i--) {
            map.put(scoresCopy[i], String.valueOf(n - i));
        }
        for (int i = 0; i < n; i++) {
            result[i] = map.get(score[i]);
        }
        return result;
    }
}