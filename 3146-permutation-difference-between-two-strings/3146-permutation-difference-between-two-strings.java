class Solution {
    public int findPermutationDifference(String s, String t) {
        Map<Character, Integer> index = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            index.put(s.charAt(i), i);
        }
        int diff = 0;
        for (int i = 0; i < t.length(); i++) {
            diff += Math.abs(i - index.get(t.charAt(i)));
        }
        return diff;
    }
}