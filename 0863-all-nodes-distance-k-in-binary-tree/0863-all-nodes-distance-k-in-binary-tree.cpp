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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        unordered_map<int, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) {
                    parent[curr->left->val] = curr;
                    q.push(curr->left);
                }
                if (curr-> right) {
                    parent[curr->right->val] = curr;
                    q.push(curr->right); 
                }
            }
        }

        unordered_map<int, bool> visited;
        q.push(target);
        while (k-- && !q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                visited[curr->val] = true;
                if (curr->left && !visited[curr->left->val]) {
                    q.push(curr->left);
                }
                if (curr->right && !visited[curr->right->val]) {
                    q.push(curr->right);
                }
                if (parent[curr->val] && !visited[parent[curr->val]->val]) {
                    q.push(parent[curr->val]);
                }
            }
        }
        
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};