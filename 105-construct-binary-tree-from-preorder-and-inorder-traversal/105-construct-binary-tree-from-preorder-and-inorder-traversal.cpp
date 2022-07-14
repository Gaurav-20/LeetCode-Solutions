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
int preorderIndex;

int search(vector<int>& inorder, int inorderStart, int inorderEnd, int data) {
    for (int i = inorderStart; i <= inorderEnd; i++) {
        if (inorder[i] == data) {
            return i;
        }
    }
    return 0;
}

TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd)
        return nullptr;
    
    TreeNode* tNode = new TreeNode(preorder[preorderIndex++]);
    if (inorderStart == inorderEnd)
        return tNode;
    
    int inorderIndex = search(inorder, inorderStart, inorderEnd, tNode->val);
    
    tNode->left = _buildTree(preorder, inorder, inorderStart, inorderIndex - 1);
    tNode->right = _buildTree(preorder, inorder, inorderIndex + 1, inorderEnd);
    
    return tNode;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 1) {
            TreeNode* t = new TreeNode(inorder[0]);
            return t;
        }
        else {
            preorderIndex = 0;
            return _buildTree(preorder, inorder, 0, inorder.size() - 1);
        }
    }
};