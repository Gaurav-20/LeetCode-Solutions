class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int counter = 0, n = piles.size();
        sort(piles.begin(), piles.end(), greater<int>());
        int you = 1, res = 0;
        while (counter++ < n / 3) {
            res += piles[you];
            you += 2;
        }
        return res;
    }
};