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
    void inorder(TreeNode* root, int& res, int& prev) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, res, prev);
        if (prev != -1) {
            res = min(res, abs(root->val - prev));
        }
        prev = root->val;
        inorder(root->right, res, prev);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX, prev = -1;
        inorder(root, res, prev);
        return res;
    }
};