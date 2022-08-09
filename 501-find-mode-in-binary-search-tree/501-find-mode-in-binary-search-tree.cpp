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
    int count = 0, prev = -1, max = INT_MIN;
    
    void traverse(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left, res);
        if (root->val == prev) {
            count++;
        } else {
            count = 1;
        }
        if (count > max) {
            max = count;
            res.clear();
            res.push_back(root->val);
        } else if (count == max) {
            res.push_back(root->val);
        }
        prev = root->val;
        traverse(root->right, res);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        traverse(root, res);
        return res;
    }
};