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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> mp;
        vector<TreeNode*> dups;
        serialize(root, mp);
        for (auto it : mp) {
            if (it.second.size() > 1) {
                dups.push_back(it.second[0]);
            }
        }
        return dups;
    }
private:
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& mp) {
        if (node == nullptr) {
            return "";
        }
        string s = 
            "(" + serialize(node->left, mp) + to_string(node->val) + serialize(node->right, mp) + ")";
        mp[s].push_back(node);
        return s;
    }
};