class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPriceYet = INT_MAX;
        int resultProfit = 0;
        for (int& price : prices) {
            minPriceYet = min(minPriceYet, price);
            resultProfit = max(resultProfit, price - minPriceYet);
        }
        return resultProfit;
    }
};