class Solution {
public:
    bool possible(vector<int>& piles, int mid, int h) {
        int hoursNeeded = 0;
        for (int& pile : piles) {
            hoursNeeded += ceil((double) pile / (double) mid);
        }
        return hoursNeeded <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int low = 1, high = piles.back();
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (possible(piles, mid, h)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (possible(piles, low, h)) {
            return low;
        } else {
            return high;
        }
    }
};