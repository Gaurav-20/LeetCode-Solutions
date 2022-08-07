const int MOD = 1000000007;

class Solution {
public:
    int power(int x, int y, int m = MOD) {
        if (y == 0) {
            return 1;
        }
        int p = power(x, y / 2, m) % m;
        p = (int)((p * (long long) p) % m);
        if (y % 2 == 0) {
            return p;
        } else {
            return (int)((x * (long long)p) % m);
        }
    }
    
    int inverse(int a) {
        return power(a, MOD - 2);
    }
    
    int dfs(const vector<vector<int>>& tree, vector<int>& subtreeSize, int node) {
        int res = 1;
        for (auto it : tree[node]) {
            res += dfs(tree, subtreeSize, it);
        }
        return subtreeSize[node] = res;
    }
    
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        vector<int> dp(n);
        vector<vector<int>> tree(n);
        for (int i = 1; i < n; i++) {
            tree[prevRoom[i]].push_back(i);
        }
        vector<int> subtreeSize(n);
        dfs(tree, subtreeSize, 0);
        
        // Find (n! / (product of subtreeSizes)) % mod
        // = n! * invModulo(product of subtreeSizes)
        long long nFact = 1;
        for (int i = 2; i <= n; i++) {
            nFact = (nFact * i) % MOD;
        }
        long long denominator = 1;
        for (int i = 0; i < n; i++) {
            denominator = (denominator * (long long) subtreeSize[i]) % MOD;
        }
        int inverseModulo = inverse((int) denominator);
        return (int) ((nFact * inverseModulo) % MOD);
    }
};