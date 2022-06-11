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
    vector<TreeNode*> nodes;
    bool isIdentical(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        } else if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        return (root1->val == root2->val) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
    
    int getDepth(TreeNode* root, int d) {
        if (root == nullptr) {
            return -1;
        }
        int depth = 1 + max(getDepth(root->left, d), getDepth(root->right, d));
        if (depth == d) {
            nodes.push_back(root);
        }
        return depth;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        } else if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        
        getDepth(root, getDepth(subRoot, -1));

        for (TreeNode* node: nodes) {
            if (isIdentical(node, subRoot)) {
                return true;
            }
        }
        return false;
    }
};