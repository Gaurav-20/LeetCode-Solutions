class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            char curr = colors[i];
            int maxVal = INT_MIN;
            int sum = 0;
            while (i < n && colors[i] == curr) {
                sum += neededTime[i];
                maxVal = max(maxVal, neededTime[i]);
                i++;
            }
            res += sum - maxVal; // exclude the largest cost
            if (i < n) {
                i--;
            }
        }
        return res;
    }
};