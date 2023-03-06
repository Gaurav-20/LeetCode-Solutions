class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] - 1 - mid < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low + k;
    }
};