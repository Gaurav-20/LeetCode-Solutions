const int MOD = 1e9 + 7;
#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxHorizontal = INT_MIN, maxVertical = INT_MIN;
        int n = horizontalCuts.size(), m = verticalCuts.size();
        maxHorizontal = max(maxHorizontal, horizontalCuts[0]);
        maxHorizontal = max(maxHorizontal, h - horizontalCuts[n - 1]);
        for (int i = 1; i < n; i++) {
            maxHorizontal = max(maxHorizontal, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        maxVertical = max(maxVertical, verticalCuts[0]);
        maxVertical = max(maxVertical, w - verticalCuts[m - 1]);
        for (int i = 1; i < m; i++) {
            maxVertical = max(maxVertical, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return mul((long long) maxHorizontal, (long long) maxVertical);
    }
};