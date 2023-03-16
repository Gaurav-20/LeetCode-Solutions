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
    unordered_map<int, int> hash;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int numNodes = inorder.size();
        for (int i = 0; i < numNodes; i++) {
            hash[inorder[i]] = i;
        }
        int postIndex = numNodes - 1;
        return build(inorder, postorder, 0, numNodes - 1, postIndex);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[postIndex--]);
        int inIndex = hash[node->val];
        node->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex);
        node->left = build(inorder, postorder, inStart, inIndex - 1, postIndex);
        return node;
    }
};