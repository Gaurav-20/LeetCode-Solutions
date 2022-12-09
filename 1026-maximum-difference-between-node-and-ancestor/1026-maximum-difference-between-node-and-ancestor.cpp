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
    
    void solve(TreeNode* root, int maxo, int mino, int &ans) {
        if (root == nullptr) {
            ans = max(ans, abs(maxo - mino));
            return;
        }
        ans = max(ans, abs(maxo - mino));
        solve(root->left, max(maxo, root->val), min(mino, root->val), ans);
        solve(root->right, max(maxo, root->val), min(mino, root->val), ans);
    }

    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        int mino = root->val;
        int maxo = root->val;
        int ans = 0;
        solve(root , maxo , mino , ans);
        return ans;
    }
};