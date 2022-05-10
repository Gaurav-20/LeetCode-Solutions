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
    bool validate(TreeNode* root, long long maximum, long long minimum) {
        if (root == nullptr) {
            return true;
        }
        return root->val < maximum && root->val > minimum && 
            validate(root->left, root->val, minimum) && 
            validate(root->right, maximum, root->val);
    }
    
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MAX, LLONG_MIN);
    }
};