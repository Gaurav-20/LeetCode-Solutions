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
    void solve(TreeNode* root, vector<int>& path, vector<vector<int>>& res, int targetSum, int currSum) {
        if (root == nullptr) {
            return;
        }

        currSum += root->val;
        path.push_back(root->val);

        if (currSum == targetSum && !(root->left || root->right)) {
            res.push_back(path);
        }

        solve(root->left, path, res, targetSum, currSum);
        solve(root->right, path, res, targetSum, currSum);

        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> res;
        solve(root, path, res, targetSum, 0);
        return res;
    }
};