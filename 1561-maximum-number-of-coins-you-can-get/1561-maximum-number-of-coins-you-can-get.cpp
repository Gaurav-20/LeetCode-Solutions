class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        
        sort(piles.begin(), piles.end(), greater<int>());
        int you = 1, bob = n - 1; // alice is always you - 1
        int res = 0;
        while (you < bob) {
            res += piles[you];
            you += 2;
            bob -= 1;
        }
        return res;
    }
};