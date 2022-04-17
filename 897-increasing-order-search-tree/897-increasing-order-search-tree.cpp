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
    TreeNode* newRoot = new TreeNode(0);
    TreeNode* dummy = newRoot;
    
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        dummy->right = new TreeNode(root->val);
        dummy->left = nullptr;
        dummy = dummy->right;
        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {        
        inorder(root);
        newRoot = newRoot->right;
        return newRoot;
    }
};