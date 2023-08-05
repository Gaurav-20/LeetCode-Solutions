/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> recurse(int l, int r) {
        if (l > r) {
            return { NULL };
        }
        vector<TreeNode*> ans;
        for (int root = l; root <= r; root++) {
            vector<TreeNode*> left = recurse(l, root - 1);
            vector<TreeNode*> right = recurse(root + 1, r);
            for (auto nodeL: left) {
                for(auto nodeR: right) {
                    TreeNode* node = new TreeNode(root);
                    node->left = nodeL;
                    node->right = nodeR;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return recurse(1, n);
    }
};