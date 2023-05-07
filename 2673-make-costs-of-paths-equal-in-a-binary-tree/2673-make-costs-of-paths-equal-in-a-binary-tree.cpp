class Solution {
public:
    int ans = 0;
    int dfs(vector<int>& cost, int i) {
        if (2 * i >= cost.size()) {
            return cost[i];
        }
        if (2 * i + 1 >= cost.size()) {
            return cost[i] + dfs(cost, 2 * i);
        }
        int left = dfs(cost, 2 * i);
        int right = dfs(cost, 2 * i + 1);
        int mx = max(left, right);
        int mn = min(left, right);
        int diff = mx - mn;
        ans += diff;
        return cost[i] + mx;
    }
    
    int minIncrements(int n, vector<int>& cost) {
        ans = 0;
        cost.insert(cost.begin(), 0);
        dfs(cost, 1);
        return ans;
    }
};