#define ll long long
class Solution {
public:
    ll putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<ll> wts;
        for (int i = 1; i < n; i++) {
            wts.push_back(weights[i - 1] + weights[i]);
        }
        sort(wts.begin(), wts.end());
        ll mini = 0;
        for (int i = 0; i < k - 1; i++) {
            mini += wts[i];
        }
        reverse(wts.begin(), wts.end());
        ll maxi = 0;
        for (int i = 0; i < k - 1; i++) {
            maxi += wts[i];
        }
        return maxi - mini;
    }
};