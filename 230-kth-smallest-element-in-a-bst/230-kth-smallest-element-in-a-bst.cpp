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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = countNodes(root->left);
        if (k <= count) {
            return kthSmallest(root->left, k);
        } else if (k > count + 1) {
            return kthSmallest(root->right, k - count - 1);
        }
        return root->val;
    }
};