class Solution {
    public int minimumOperationsToMakeKPeriodic(String word, int k) {
        int n = word.length();
        Map<String, Integer> freq = new HashMap<>();
        for (int i = 0; i < n; i += k) {
            String sub = word.substring(i, i + k);
            freq.put(sub, freq.getOrDefault(sub, 0) + 1);
        }
        int result = Integer.MAX_VALUE;
        for (Integer value : freq.values()) {
            result = Math.min(result, n / k - value);
        }
        return result;
    }
}