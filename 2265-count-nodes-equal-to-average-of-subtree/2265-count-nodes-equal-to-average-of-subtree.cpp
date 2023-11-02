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
    int res = 0;
    
    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) {
            return { 0, 0 };
        }
        pair<int, int> leftRes = solve(root->left);
        pair<int, int> rightRes = solve(root->right);
        int sum = root->val + leftRes.first + rightRes.first;
        int count = 1 + leftRes.second + rightRes.second;
        if (root->val == sum / count) {
            res++;
        }
        return { sum, count };
    }
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return res;
    }
};