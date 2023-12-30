class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] result = new int[num_people];
        int iterCount = 0;
        while (candies > 0) {
            for (int i = 0; i < num_people; i++) {
                int candyToGive = Math.min(candies, num_people * iterCount + i + 1);
                result[i] += candyToGive;
                candies -= candyToGive;
                if (candies == 0) {
                    break;
                }
            }
            iterCount += 1;
        }
        return result;
    }
}