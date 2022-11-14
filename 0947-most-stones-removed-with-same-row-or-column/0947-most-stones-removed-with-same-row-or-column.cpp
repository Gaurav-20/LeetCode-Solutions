int unions[1001];

int find(int x) {
    if (unions[x] == x) {
        return x;
    }
    return find(unions[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    unions[y] = x;
}

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int len = stones.size();
        for (int i = 0; i < len; i++) {
            unions[i] = i;
        }
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unite(i, j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (unions[i] != i) {
                res++;
            }
        }
        return res;
    }
};