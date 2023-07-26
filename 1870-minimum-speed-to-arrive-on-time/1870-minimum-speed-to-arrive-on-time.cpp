class Solution {
public:
    bool possibleBySpeed(vector<int>& dist, double hour, int speed, int n) {
        double finalHour = 0.0;
        for (int i = 0; i < n; i++) {
            double currHour = (double) dist[i] / (double) speed;
            if (i == n - 1) {
                finalHour += currHour;
            } else {
                finalHour += ceil(currHour);
            }
        }
        return hour >= finalHour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long low = 1, high = 1e8, n = dist.size(), result = -1;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (possibleBySpeed(dist, hour, mid, n)) {
                result = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};