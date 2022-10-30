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
    unordered_map<TreeNode*, int> heights;
    unordered_map<int, int> dp;
    
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return heights[root] = 1 + max(height(root->left), height(root->right));
    }
    
    void dfs(TreeNode* root, int depth, int mx) {
        if (root == nullptr) {
            return;
        }
        dp[root->val] = mx;
        dfs(root->left, depth + 1, max(mx, depth + heights[root->right]));
        dfs(root->right, depth + 1, max(mx, depth + heights[root->left]));
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> res;
        height(root);
        dfs(root, 0, 0);
        for (int query : queries) {
            res.push_back(dp[query]);
        }
        return res;
    }
};