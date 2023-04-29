class Solution {
public:
     void unionByRank(int x, int y, int limit, vector<int>& parent, vector<int>& rank, vector<int>& weight) {
        int xRef = find(x, INT_MAX, parent, weight);
        int yRef = find(y, INT_MAX, parent, weight);
        if (xRef != yRef) {
            if (rank[xRef] < rank[yRef]) {
                parent[xRef] = yRef;
                weight[xRef] = limit;
            } else {
                parent[yRef] = xRef;
                weight[yRef] = limit;
                if (rank[xRef] == rank[yRef]) {
                    rank[xRef]++;
                }
            }
        }
    }
    
    int find(int x, int limit, vector<int>& parent, vector<int>& weight) {
        while (x != parent[x]) {
            if (weight[x] >= limit) {
                break;
            }
            x = parent[x];
        }
        return x;
    }
    
     bool isConnectedAndWithinLimit(int p, int q, int limit, vector<int>& parent, vector<int>& weight) {
        return find(p, limit, parent, weight) == find(q, limit, parent, weight);
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> parent(n);
        vector<int> rank(n);
        vector<int> weight(n);
        for (int i = 0; i < n ; i++) {
            parent[i] = i;
        }
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        for (vector<int>& edge: edgeList) {
            unionByRank(edge[0], edge[1], edge[2], parent, rank, weight);
        }

        vector<bool> res;
        for (vector<int>& q: queries) {
            res.push_back(isConnectedAndWithinLimit(q[0], q[1], q[2], parent, weight));
        }
        return res;
    }
};