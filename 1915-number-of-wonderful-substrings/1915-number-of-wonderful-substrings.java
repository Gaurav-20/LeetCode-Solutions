class Solution {
    public long wonderfulSubstrings(String word) {
        long count = 0;
        int[] freq = new int[1024];
        freq[0] = 1;
        int value = 0;
        for (char c : word.toCharArray()) {
            value ^= (1 << (c - 'a'));
            count += freq[value];
            for (int j = 0; j < 10; j++) {
                int mask = (1 << j);
                count += freq[value ^ mask];
            }
            freq[value]++;
        }
        return count;
    }
}