class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int numBottlesDrunk = numBottles;
        int numEmptyBottles = numBottles;
        while (numEmptyBottles >= numExchange) {
            numEmptyBottles -= numExchange;
            numBottlesDrunk += 1;
            numEmptyBottles += 1;
            numExchange += 1;
        }
        return numBottlesDrunk;
    }
}