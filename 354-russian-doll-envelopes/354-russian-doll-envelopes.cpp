bool comp(const vector<int> &a, const vector<int> &b) {
    return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = size(envelopes);
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> lis; // longest increasing subsequence
        lis.push_back(envelopes[0][1]);
        for (int i = 1; i < n; i++) {
            int index = lower_bound(lis.begin(), lis.end(), envelopes[i][1]) - lis.begin();
            if (index == size(lis)) {
                lis.push_back(envelopes[i][1]);
            } else {
                lis[index] = envelopes[i][1];
            }
        }
        return size(lis);
    }
};