class Solution {
public:
    bool satisfiesHIndex(vector<int>& citations, int mid) {
        int res = 0;
        for (int cite: citations) {
            if (cite >= mid) {
                res++;
            }
        }
        return res >= mid;
    }
    
    int hIndex(vector<int>& citations) {
        int low = 0, high = *max_element(citations.begin(), citations.end());
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (satisfiesHIndex(citations, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        if (satisfiesHIndex(citations, high)) {
            return high;
        }
        return low;
    }
};