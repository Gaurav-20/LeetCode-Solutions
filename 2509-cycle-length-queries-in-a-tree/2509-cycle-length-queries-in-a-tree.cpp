class Solution {
public:
    int leastCommonAncestorDistance(int a, int b) {
        vector<int> va, vb;
        while (a != 1) {
            va.push_back(a);
            a /= 2;
        }
        va.push_back(a);
        while (b != 1) {
            vb.push_back(b);
            b /= 2;
        }
        vb.push_back(b);
        reverse(va.begin(), va.end());
        reverse(vb.begin(), vb.end());
        int i = 0, j = 0;
        while (i < va.size() && j < vb.size()) {
            if (va[i] != vb[j]) {
                break;
            }
            i++, j++;
        }
        return va.size() - i + vb.size() - j + 1;
    }
    
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        for (auto query : queries) {
            res.push_back(leastCommonAncestorDistance(query[0], query[1]));
        }
        return res;
    }
};