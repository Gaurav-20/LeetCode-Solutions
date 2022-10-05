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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> q;
        q.push(root);
        for (int i = 0; i < depth - 2; i++) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            TreeNode* temp = curr->left;
            curr->left = new TreeNode(val);
            curr->left->left = temp;
            temp = curr->right;
            curr->right = new TreeNode(val);
            curr->right->right = temp;
        }
        return root;

    }
};