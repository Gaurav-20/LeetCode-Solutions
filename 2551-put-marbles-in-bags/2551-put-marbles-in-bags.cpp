class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> wts;
        for (int i = 1; i < n; i++) {
            wts.push_back(weights[i - 1] + weights[i]);
        }
        sort(wts.begin(), wts.end());
        long long mini = 0;
        for (int i = 0; i < k - 1; i++) {
            mini += wts[i];
        }
        long long maxi = 0;
        for (int i = 0; i < k - 1; i++) {
            maxi += wts[wts.size() - i - 1];
        }
        return maxi - mini;
    }
};