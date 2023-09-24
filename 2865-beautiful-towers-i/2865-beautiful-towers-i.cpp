class Solution {
public:
    long long findMaxHeightWithPeakIndex(vector<int>& maxHeights, int peakIndex, int n) {
        long long res = maxHeights[peakIndex];
        for (int i = peakIndex - 1; i >= 0; i--) {
            long long currHeight = min(maxHeights[i], maxHeights[i + 1]);
            res += currHeight;
            maxHeights[i] = currHeight;
        }
        for (int i = peakIndex + 1; i < n; i++) {
            long long currHeight = min(maxHeights[i], maxHeights[i - 1]);
            res += currHeight;
            maxHeights[i] = currHeight;
        }
        return res;
    }
    
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long res = 0;
        for (int idx = 0; idx < n; idx++) {
            vector<int> temp = maxHeights;
            res = max(res, findMaxHeightWithPeakIndex(temp, idx, n));
        }
        return res;
    }
};