class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        int[][] mat = new int[26][26];
        for (int i = 0; i < 26; i++) {
            Arrays.fill(mat[i], (int) 1e9);
            mat[i][i] = 0;
        }
        for (int i = 0; i < cost.length; i++) {
            int originalIdx = original[i] - 'a';
            int changedIdx = changed[i] - 'a';
            mat[originalIdx][changedIdx] = Math.min(cost[i], mat[originalIdx][changedIdx]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (mat[i][k] == 1e9 || mat[k][j] == 1e9) {
                        continue;
                    }
                    mat[i][j] = Math.min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        long result = 0;
        for (int i = 0; i < source.length(); i++) {
            int sourceIdx = source.charAt(i) - 'a';
            int targetIdx = target.charAt(i) - 'a';
            if (sourceIdx != targetIdx) {
                if (mat[sourceIdx][targetIdx] == 1e9) {
                    return -1;
                } else {
                    result += mat[sourceIdx][targetIdx];
                }
            }
        }
        return result;
    }
}