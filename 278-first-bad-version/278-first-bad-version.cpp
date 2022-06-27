// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            bool curr = isBadVersion(mid);
            if (curr) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (isBadVersion(low)) {
            return low;
        } else {
            return high;
        }
    }
};