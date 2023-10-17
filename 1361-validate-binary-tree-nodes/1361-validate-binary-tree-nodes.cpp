class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int count = n;
        for (int i = 0; i < count; i++) {
            int l = leftChild[i], r = rightChild[i];
            if (l != -1) {
                int left = find(l), root = find(i);
                if (left != l || left == root) {
                    return false;
                }
                parent[left] = root;
                n -= 1;
            }
            if (r != -1) {
                int right = find(r), root = find(i);
                if (right != r || root == right) {
                    return false;
                }
                parent[right] = root;
                n -= 1;
            }
        }
        return n == 1;
    }
};