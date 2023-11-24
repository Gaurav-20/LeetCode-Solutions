class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        
        sort(piles.begin(), piles.end(), greater<int>());
        int alice = 0, you = 1, bob = n - 1;
        int res = 0;
        while (you < bob) {
            res += piles[you];
            alice += 2;
            you += 2;
            bob -= 1;
        }
        return res;
    }
};