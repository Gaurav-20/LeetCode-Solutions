class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int score = 0, maxScore = 0;
        int i = 0, j = tokens.length - 1;
        while (i <= j) {
            if (tokens[i] <= power) {
                score += 1;
                power -= tokens[i];
                i++;
            } else if (score > 0) {
                score -= 1;
                power += tokens[j];
                j--;
            } else {
                break;
            }
            maxScore = Math.max(maxScore, score);
        }
        return maxScore;
    }
}