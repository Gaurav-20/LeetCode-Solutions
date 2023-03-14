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
    void recur(TreeNode* root, int pathSum, int& totalSum) {
        pathSum = pathSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            totalSum += pathSum;
            return;
        }
        if (root->left) {
            recur(root->left, pathSum, totalSum);
        }
        if (root->right) {
            recur(root->right, pathSum, totalSum);
        }
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        recur(root, 0, ans);
        return ans;
    }
};