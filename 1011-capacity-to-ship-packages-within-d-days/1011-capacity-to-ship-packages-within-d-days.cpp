class Solution {
public:
    bool possible(vector<int>& weights, int days, int cap) {
        int day = 0, count = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > cap) {
                return false;
            }
            if (count + weights[i] > cap) {
                day++;
                count = 0;
                i--;
            } else {
                count += weights[i];
            }
        }
        if (count > 0) {
            day++;
        }
        return day <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1, high = 1e8;
        int res = INT_MAX;
        while (high - low >= 1) {
            int mid = low + (high - low) / 2;
            if (possible(weights, days, mid)) {
                res = min(res, mid);
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};