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
    int good(TreeNode* root, int max) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val >= max) {
            return 1 + good(root->left, root->val) + good(root->right, root->val);
        } else {
            return good(root->left, max) + good(root->right, max);
        }
    }
    int goodNodes(TreeNode* root) {
        int max = INT_MIN;
        return good(root, max);
    }
};