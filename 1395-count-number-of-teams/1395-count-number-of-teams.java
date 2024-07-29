class Solution {
    public int numTeams(int[] rating) {
        int n = rating.length, result = 0;
        for (int i = 0; i < n; i++) {
            int leftMin = 0, leftMax = 0, rightMin = 0, rightMax = 0;
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    if (rating[j] > rating[i]) {
                        leftMax += 1;
                    } else {
                        leftMin += 1;
                    }
                }
                if (i < j) {
                    if (rating[j] > rating[i]) {
                        rightMax += 1;
                    } else {
                        rightMin += 1;
                    }
                }
            }
            result += leftMin * rightMax + leftMax * rightMin;
        }
        return result;
    }
}