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

const int LEFT = 0;
const int RIGHT = 1;

class Solution {
public:
    int res = 0;
    
    void maxZigZag(TreeNode* root, int dir, int currLength) {
        if (root == nullptr) {
            return;
        }
        res = max(res, currLength);
        maxZigZag(root->left, LEFT, (dir == RIGHT) ? currLength + 1 : 1);
        maxZigZag(root->right, RIGHT, (dir == LEFT) ? currLength + 1 : 1);
    }
    
    int longestZigZag(TreeNode* root) {
        maxZigZag(root, LEFT, 0);
        maxZigZag(root, RIGHT, 0);
        return res;
    }
};