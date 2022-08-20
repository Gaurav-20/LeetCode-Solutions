class Solution {
public:
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) {
            return 0;
        }
        priority_queue<int> pq;
        int i = 0, n = stations.size(), stops = 0, maxDistance = startFuel;
        while (maxDistance < target) {
            while (i < n && stations[i][0] <= maxDistance) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()) {
                return -1;
            }
            maxDistance += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};