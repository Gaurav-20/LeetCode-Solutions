class UnionFind {
    int num;
    vector<int> rank;
    vector<int> parent;
public:
    UnionFind(int n) {
        num = n;
        rank = vector<int>(n, 0);
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int size() {
        return num;
    }
    
    int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    
    void unionn(int p, int q) {
        int rootp = find(p);
        int rootq = find(q);
        if (rootp == rootq) {
            return;
        }
        if (rank[rootp] < rank[rootq]) {
            parent[rootp] = rootq;
        } else {
            parent[rootq] = rootp;
            if (rank[rootp] == rank[rootq]) {
                rank[rootp]++;
            }
        }
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind unionFind(26);
        for (string& eq : equations) {
            int left  = eq[0] - 'a';
            int right = eq[3] - 'a';
            bool equal = eq[1] == '=';
            if (equal) {
                unionFind.unionn(left, right);
            }
        }
        for (string& eq : equations) {
            int left  = eq[0] - 'a';
            int right = eq[3] - 'a';
            bool unequal = eq[1] == '!';
            if (unequal) {
                if (unionFind.isConnected(left, right)) {
                    return false;
                }
            }
        }
        return true;
    }
};