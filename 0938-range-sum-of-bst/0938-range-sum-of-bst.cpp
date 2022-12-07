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
    int solve(TreeNode* root, int low, int high, int &res) {
        if (root == nullptr) {
            return 0;
        }
        int left = solve(root->left, low, high, res);
        int right = solve(root->right, low, high, res);
        if (root->val >= low && root->val <= high) {
            res += root->val + left + right;
        }
        return left + right;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        solve(root, low, high, res);
        return res;
    }
};