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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        } else if (depth == 0) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->right = root;
            return newRoot;
        }
        if (root == nullptr) {
            return root;
        } else if (depth == 2) {
            root->left  = addOneRow(root->left,  val, 1);
            root->right = addOneRow(root->right, val, 0);
            return root;
        } else if (depth > 2) {
            root->left  = addOneRow(root->left,  val, depth - 1);
            root->right = addOneRow(root->right, val, depth - 1);
        }
        return root;
    }
};