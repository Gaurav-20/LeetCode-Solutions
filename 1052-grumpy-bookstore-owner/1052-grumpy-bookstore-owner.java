class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int n = grumpy.length;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }
        int loss = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                loss += customers[i];
            }
        }
        int maxLoss = loss;
        for (int i = minutes; i < n; i++) {
            if (grumpy[i - minutes] == 1) {
                loss -= customers[i - minutes];
            }
            if (grumpy[i] == 1) {
                loss += customers[i];
            }
            maxLoss = Math.max(maxLoss, loss);
        }
        return sum + maxLoss; // convert the max possible loss to profit by using secret technique
    }
}