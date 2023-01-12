class Solution {
public:
    
    void solve(vector<vector<int>>& tree, int node, int prevNode,
        vector<int>& charCount, string& labels, vector<int>& res) {

        int index = labels[node] - 'a';
        int prevCount = charCount[index];
        charCount[index]++;
        for (auto nextNode : tree[node]) {
            if (prevNode == nextNode) {
                continue;
            }
            solve(tree, nextNode, node, charCount, labels, res);
        }
        res[node] = charCount[index] - prevCount;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> tree(n);
        for (auto edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n, 0);
        vector<int> charCount(26, 0);
        solve(tree, 0, 0, charCount, labels, res);
        return res;
    }
};