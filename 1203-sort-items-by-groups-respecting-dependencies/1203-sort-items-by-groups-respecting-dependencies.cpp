class Solution {
public:
    vector<int> topoSort(auto& adj, vector<int>& deg, int sz) {
        queue<int> q;
        for (int i = 0; i < sz; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            res.push_back(x);
            for (int y: adj[x]) {
                deg[y]--;
                if (deg[y] == 0) {
                    q.push(y);
                }
            }
        }
        for (int i = 0; i < sz; i++) {
            if (deg[i] > 0) {
                return {};
            }
        }
        return res;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }
        vector<vector<int>> adjItem(n);
        vector<int> degGroup(m, 0), degItem(n, 0);
        vector<unordered_set<int>> adjGroupSet(m);
        for (int i = 0; i < n; i++) {
            int toI = group[i];
            for (int from: beforeItems[i]) {
                int fromJ = group[from];
                if (toI != fromJ && adjGroupSet[fromJ].count(toI) == 0) {
                    adjGroupSet[fromJ].insert(toI);
                    degGroup[toI]++;
                }
                adjItem[from].push_back(i);
                degItem[i]++;
            }
        }
        
        vector<int> sortGroup = topoSort(adjGroupSet, degGroup, m);
        vector<int> sortItem = topoSort(adjItem, degItem, n);
        if (sortGroup.empty() || sortItem.empty()) {
            return {};
        }
        vector<vector<int>> itemGp(m);
        for (int i: sortItem) {
            itemGp[group[i]].push_back(i);
        }
        
        vector<int> res;
        for (int i: sortGroup) {
            for (int item: itemGp[i]) {
                res.push_back(item);
            }
        }
        return res;
    }
};