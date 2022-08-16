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
    TreeNode* prune(TreeNode* root) {
        if (root == nullptr) {    
            return root;
        }
        TreeNode* lres = prune(root->left);
        root->left = lres;
        TreeNode* rres = prune(root->right);
        root->right = rres;
        if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        return root;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return prune(root);
    }
};