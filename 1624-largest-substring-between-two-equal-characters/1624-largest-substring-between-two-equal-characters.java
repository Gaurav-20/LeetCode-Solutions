class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int result = -1;
        int[] lastIdx = new int[26];
        Arrays.fill(lastIdx, -1);
        for (int i = 0; i < s.length(); i++) {
            int idx = s.charAt(i) - 'a';
            if (lastIdx[idx] == -1) {
                lastIdx[idx] = i;
            } else {
                result = Math.max(result, i - lastIdx[idx] - 1);
            }
        }
        return result;
    }
}