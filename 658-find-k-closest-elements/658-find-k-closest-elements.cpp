class Solution {
public:
    bool isICloserThanJ(int a, int b, int x) {
        int absa = abs(a - x);
        int absb = abs(b - x);
        return (absa < absb) || ((absa == absb) && (a < b));
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        int i = low, j = low + 1;
        if (isICloserThanJ(arr[high], arr[low], x)) {
            i = high;
            j = high + 1;
        }
        vector<int> res;
        while (res.size() < k && i >= 0 && j < n) {
            if (isICloserThanJ(arr[i], arr[j], x)) {
                res.insert(res.begin(), arr[i]);
                i--;
            } else {
                res.push_back(arr[j]);
                j++;
            }
        }
        while (res.size() < k && i >= 0) {
            res.insert(res.begin(), arr[i]);
            i--;
        }
        while (res.size() < k && j < n) {
            res.push_back(arr[j]);
            j++;
        }
        return res;
    }
};