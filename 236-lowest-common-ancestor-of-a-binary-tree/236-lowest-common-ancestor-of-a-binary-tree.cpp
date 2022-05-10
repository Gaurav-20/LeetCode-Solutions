/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If the root itself is nullptr or if the root is pointing at p or q
        // return this root
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        // Recursive calls
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // Both left and right nullptr is handled by base case
        // If we get nullptr from left, return right which isn't nullptr and vice versa
        // If both are not nullptr, the root is at the lca so return this
        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else {
            return root;
        }
    }
};