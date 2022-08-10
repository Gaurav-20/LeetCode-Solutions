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
    bool traverse(TreeNode* root, unordered_set<int>& st, int k) {
        if (root == nullptr) {
            return false;
        }
        if (st.count(k - root->val)) {
            return true;
        }
        st.insert(root->val);
        return traverse(root->left, st, k) || traverse(root->right, st, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return traverse(root, st, k);
    }
};