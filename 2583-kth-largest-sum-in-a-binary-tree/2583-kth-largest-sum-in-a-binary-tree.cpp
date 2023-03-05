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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }
        unordered_map<int, long long> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({ root, 0 });
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int lvl = q.front().second;
            q.pop();
            mp[lvl] += cur->val;
            if (cur->left) {
                q.push({ cur->left, lvl + 1 });
            }
            if (cur->right) {
                q.push({ cur->right, lvl + 1 });
            }
        }
        vector<long long> sum;
        for (auto it : mp) {
            sum.push_back(it.second);
        }
        if (sum.size() < k) {
            return -1;
        }
        sort(sum.begin(), sum.end(), greater<long long>());
        return sum[k - 1];
    }
};