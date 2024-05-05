class Solution {
    public int minimumOperationsToMakeKPeriodic(String word, int k) {
        Map<String, Integer> freq = new HashMap<>();
        for (int i = 0; i < word.length(); i += k) {
            String sub = word.substring(i, i + k);
            freq.put(sub, freq.getOrDefault(sub, 0) + 1);
        }
        int result = Integer.MAX_VALUE;
        int totalSubstrings = word.length() / k;
        for (Integer value : freq.values()) {
            result = Math.min(result, totalSubstrings - value);
        }
        return result;
    }
}