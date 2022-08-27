class Solution {
public:
    int find(vector<int> &arr, int &k){
        int sum = 0, res = INT_MIN;
        set<int> s;
        for (auto i : arr) {
            sum += i;
            if (sum <= k) {
                res = max(res, sum);
            }
            auto it = s.lower_bound(sum - k);
            if (it != s.end()) {
                res = max(res, sum - *it);
            }
            s.insert(sum);
        }
        return res;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN;
        for (int i = 0; i < matrix[0].size(); i++) {
            vector<int> arr(matrix.size(), 0);
            for (int j = i; j < matrix[0].size(); j++) {
                for (int k = 0; k < matrix.size(); k++) {
                    arr[k] += matrix[k][j];
                }
                res = max(res, find(arr, k));
            }
        }
        return res;
    }
};