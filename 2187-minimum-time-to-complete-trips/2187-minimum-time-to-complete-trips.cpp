class Solution {
public:
    bool possibleInTime(vector<int>& time, long long totalTrips, long long mid, int n) {
        long long trips = 0;
        for (int i = 0; i < n; i++) {
            trips += mid / time[i];
        }
        return trips >= totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        sort(time.begin(), time.end());
        long long low  = 1;
        long long high = (long long) totalTrips * (long long) time[0];
        while (low < high) {
            long long mid = low + (high - low) / 2LL;
            if (possibleInTime(time, totalTrips, mid, n)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};