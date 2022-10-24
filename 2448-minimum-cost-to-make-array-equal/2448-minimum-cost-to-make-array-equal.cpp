class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = { nums[i], costs[i] };
        }
        sort(arr.begin(), arr.end());
        long long total = accumulate(costs.begin(), costs.end(), 0LL), count = 0;
        long long target;
        for (int i = 0; i < n; i++) {
            int num = arr[i].first, cost = arr[i].second;
            count += cost;
            if (count > total / 2) {
                target = num;
                break;
            }
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int num = arr[i].first, cost = arr[i].second;
            res += cost * abs(num - target);
        }
        return res;
    }
};