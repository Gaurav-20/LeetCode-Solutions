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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<pair<TreeNode*, long long>> q;
        q.push({ root, 0 });
        int maxWidth = 0;
        while (!q.empty()) {
            int sz = q.size();
            long long minId = q.front().second;
            int firstIndex, lastIndex;
            for (int i = 1; i <= sz; i++) {
                TreeNode* node = q.front().first;
                long long curId = q.front().second - minId;
                q.pop();
                if (i == 1) {
                    firstIndex = curId;
                }
                if (i == sz) {
                    lastIndex = curId;
                }
                if (node->left) {
                    q.push({ node->left, curId * 2 + 1 });
                }
                if (node->right) {
                    q.push({ node->right, curId * 2 + 2 });
                }
            }
            maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
        }
        return maxWidth;
    }
};