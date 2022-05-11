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
    int res = 0;
    
    int solve(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftRes = solve(root->left);
        int rightRes = solve(root->right);
        res += abs(leftRes) + abs(rightRes);
        return root->val + leftRes + rightRes - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        solve(root);
        return res;
    }
};