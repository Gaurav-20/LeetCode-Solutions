class Solution {
    public int buyChoco(int[] prices, int money) {
        int cheapest = Integer.MAX_VALUE, secondCheapest = Integer.MAX_VALUE;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < cheapest) {
                secondCheapest = cheapest;
                cheapest = prices[i];
            } else if (prices[i] == cheapest) {
                secondCheapest = cheapest;
            } else if (prices[i] < secondCheapest) {
                secondCheapest = prices[i];
            }
        }
        return (cheapest + secondCheapest > money) ? money : money - cheapest - secondCheapest;
    }
}