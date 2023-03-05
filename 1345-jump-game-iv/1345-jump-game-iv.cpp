class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return 0;
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<bool> vis(n, false);
        queue<int> q;
        vis[0] = true;
        q.push(0);
        int ans = 0;
        while (!q.empty()) {
           int k = q.size();
            for (int i = 0; i < k; i++) {
                int v = q.front();
                q.pop();
                if (v == n - 1) {
                    return ans;
                }
                if (mp.find(arr[v]) != mp.end()) {
                    auto it = mp.find(arr[v]);
                    vector<int> a = it->second;
                    for(auto r : a) {
                        if (!vis[r]) {
                            vis[r] = true;
                            q.push(r);
                        }
                    }
                    mp.erase(it);
                }
                if (v - 1 >= 0 && !vis[v - 1]) {
                     q.push(v - 1);
                     vis[v - 1] = true;
                }
                if (v + 1 < n && !vis[v + 1]) {
                    q.push(v + 1);
                    vis[v + 1] = true;
                }
            }
            ans++;
        }
        return 0;
    }
};