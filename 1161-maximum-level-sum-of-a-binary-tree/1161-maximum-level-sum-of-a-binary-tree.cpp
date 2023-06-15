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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int maxSum = INT_MIN;
        int maxLevel = -1;
        while (!q.empty()) {
            int size = q.size();
            int currLevelSum = 0;
            level++;
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                currLevelSum += curr->val;
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            if (currLevelSum > maxSum) {
                maxSum = currLevelSum;
                maxLevel = level;
            }
        }
        return maxLevel;
    }
};