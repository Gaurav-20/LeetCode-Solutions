class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        int maxTillNow = -1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] = maxTillNow;
            maxTillNow = max(maxTillNow, arr[i]);
        }
        return res;
    }
};