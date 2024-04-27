class Solution {
    public int ringLength;
    public int keyLength;
    
    public int findRotateSteps(String ring, String key) {
        this.ringLength = ring.length();
        this.keyLength = key.length();
        Integer[][] dp = new Integer[ringLength][keyLength];
        Map<Character, List<Integer>> index = new HashMap<>();
        for (int i = 0; i < ringLength; i++) {
            char ch = ring.charAt(i);
            if (index.get(ch) == null) {
                index.put(ch, new ArrayList<>());
            }
            index.get(ch).add(i);
        }
        return solve(ring, key, 0, 0, dp, index);
    }
    
    public int solve(String ring, String key, int ringIdx, int keyIdx, Integer[][] dp, Map<Character, List<Integer>> index) {
        if (keyIdx >= keyLength) {
            return 0;
        }
        if (dp[ringIdx][keyIdx] != null) {
            return dp[ringIdx][keyIdx];
        }
        char keyCh = key.charAt(keyIdx);
        int rotations = Integer.MAX_VALUE;
        for (Integer idx : index.get(keyCh)) {
            int left = Math.abs(ringIdx - idx);
            int right = ringLength - Math.abs(ringIdx - idx);
            rotations = Math.min(rotations, Math.min(left, right) + solve(ring, key, idx, keyIdx + 1, dp, index));
        }
        return dp[ringIdx][keyIdx] = rotations + 1; // 1 for spelling
    }
}