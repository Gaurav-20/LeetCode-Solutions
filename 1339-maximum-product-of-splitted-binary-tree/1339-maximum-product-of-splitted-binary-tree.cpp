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

const int MOD = 1e9 + 7;

class Solution {
public:
    
    long long solve(TreeNode* root, long long& sum, long long& res) {
        if (root == nullptr) {
            return 0LL;
        }
        long long currSum = root->val + solve(root->left, sum, res) + solve(root->right, sum, res);
        res = max(res, currSum * (sum - currSum));
        return currSum;
    }
    
    int maxProduct(TreeNode* root) {
        long long sum = 0, res = 0;
        sum = solve(root, sum, res);
        solve(root, sum, res);
        return res % MOD;
    }
};