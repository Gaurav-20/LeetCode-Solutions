class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<vector<int>> vec(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int av = aliceValues[i], bv = bobValues[i];
            vec[i] = { av + bv, av, bv };
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; i++) {
            res += (i % 2) ? 0 : vec[n - i - 1][1]; // Alice turn
            res -= (i % 2) ? vec[n - i - 1][2] : 0; // Bob turn
        }    
        return (res > 0) - (res < 0); // signum function
    }
};