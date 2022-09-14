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
    int res;
    int freq[10];
    
    void solve(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        freq[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            int odd = 0;
            for (auto it : freq) {
                if (it & 1) {
                    odd++;
                }
            }
            if (odd <= 1) {
                res++;
            }
        }
        solve(root->left);
        solve(root->right);
        freq[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        res = 0;
        solve(root);
        return res;
    }
};