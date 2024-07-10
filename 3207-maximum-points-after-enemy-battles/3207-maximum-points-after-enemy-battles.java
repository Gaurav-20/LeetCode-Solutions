class Solution {
    public long maximumPoints(int[] enemyEnergies, int currentEnergy) {
        Arrays.sort(enemyEnergies);
        if (currentEnergy < enemyEnergies[0]) {
            return 0;
        }
        long finalEnergy = currentEnergy;
        for (int i = enemyEnergies.length - 1; i > 0; i--) {
            finalEnergy += enemyEnergies[i];
        }
        return finalEnergy / enemyEnergies[0];
    }
}