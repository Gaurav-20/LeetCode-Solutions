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

struct Node {
    TreeNode* curr;
    int index;
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<Node> q;
        q.push({ root, 0 });
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front().curr;
                int index = q.front().index;
                q.pop();
                if (index != i) {
                    return false;
                }
                if (curr->left) {
                    q.push({ curr->left, index * 2 });
                }
                if (curr->right) {
                    q.push({ curr->right, index * 2 + 1 });
                }
            }
            if (!q.empty() && size != pow(2, level)) {
                return false;
            }
            level++;
        }
        return true;
    }
};