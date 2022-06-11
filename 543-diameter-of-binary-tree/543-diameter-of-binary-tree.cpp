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
    int findDiameter(TreeNode* root, int& res) {
        if (root == nullptr)
            return 0;
        int leftHeight = findDiameter(root->left, res);
        int rightHeight = findDiameter(root->right, res);
        int temp = 1 + max(leftHeight, rightHeight);
        int ans = max(temp, leftHeight + rightHeight + 1);
        res = max(res, ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        findDiameter(root, res);
        return --res;
    }
};