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
    int findMaxPath(TreeNode* root, int& res) {
        if (root == nullptr) {
            return 0;
        }
        int leftSum = findMaxPath(root->left, res);
        int rightSum = findMaxPath(root->right, res);
        leftSum = max(0, leftSum);
        rightSum = max(0, rightSum);
        res = max(res, root->val + leftSum + rightSum);
        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        findMaxPath(root, res);
        return res;
    }
};