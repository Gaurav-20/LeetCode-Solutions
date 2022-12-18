class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 1);
        map<pair<int, int>, bool> hasEdge;
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            degree[u]++;
            degree[v]++;
            hasEdge[{ u, v }] = 1;
            hasEdge[{ v, u }] = 1;
        }
        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (degree[i] % 2 == 1) {
                odd.push_back(i);
            }
        }
        if (odd.size() % 2 || odd.size() > 4) {
            return false;
        }
        if (odd.size() == 0) {
            return true;
        }
        if (odd.size() == 2) {
            int a = odd[0];
            int b = odd[1];
            if (hasEdge[{ a, b }]) {
                for (int i = 1; i <= n; i++) {
                    if (i == a || i == b) {
                        continue;
                    }
                    if (!hasEdge[{ i ,a }] && !hasEdge[{ i, b }]) {
                        return true;
                    }
                }
                return false;
            } else {
                return true;
            }
        } else if (odd.size() == 4) {
            int a = odd[0];
            int b = odd[1];
            int c = odd[2];
            int d = odd[3];
            if (!hasEdge[{ a, b }] && !hasEdge[{ c, d }]) {
                return true;
            }
            if (!hasEdge[{ a, c }] && !hasEdge[{ b, d }]) {
                return true;
            }
            if (!hasEdge[{ a, d }] && !hasEdge[{ c, b }]) {
                return true;
            }
            return false;
        }
        return false;
    }
};