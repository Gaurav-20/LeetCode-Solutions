/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* result;
    
    void traverseTree(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) {
            return;
        }
        traverseTree(original->left, cloned->left, target);
        if (original == target) {
            result = cloned;
        }
        traverseTree(original->right, cloned->right, target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        result = nullptr;
        traverseTree(original, cloned, target);
        return result;
    }
};