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
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, res);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(root->val);
        }
        inorder(root->right, res);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        inorder(root1, leaf1);
        inorder(root2, leaf2);
        return leaf1 == leaf2;
    }
};