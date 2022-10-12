class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return aliceValues[i] + bobValues[i] > aliceValues[j] + bobValues[j];
        });
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += i % 2 ? 0 : aliceValues[idx[i]]; // Alice turn
            res -= i % 2 ? bobValues[idx[i]] : 0; // Bob turn
        }
        return (res > 0) - (res < 0); // signum function
    }
};