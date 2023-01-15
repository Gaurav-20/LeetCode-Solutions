class Solution {
public:
    
    int find(vector<int>& parent, int i) {
        return (parent[i] == i) ? i : parent[i] = find(parent, parent[i]);    
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), res = n;
        sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b) {
            return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]); 
        });
        vector<int> parent(n), componentSize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            componentSize[i] = 1;
        }

        for (vector<int>& edge : edges) {
            int par1 = find(parent, edge[0]), par2 = find(parent, edge[1]);
            if (vals[par1] == vals[par2]) {
                res += componentSize[par1] * componentSize[par2];
                componentSize[par1] += componentSize[par2];
                parent[par2] = par1;
            } else {
                if (vals[par1] > vals[par2]) {
                    parent[par2] = par1;
                } else {
                    parent[par1] = par2;
                }
            }
        }
        return res;
    }
};