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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*, int>> st;
        st.push({ root, 0 });
        while (!st.empty()) {
            auto t = st.top();
            TreeNode* curr = t.first;
            int state = t.second;      
            st.pop();
            if (curr == nullptr || state == 3)  {
        	    continue;
            }
            st.push({ curr, state + 1 });
            if (state == 0) {
        	    res.push_back(curr->val);
            } else if (state == 1) {
        	    st.push({ curr->left, 0});
            } else if (state == 2)  {
        	    st.push({ curr->right, 0 });
            }
        }
        return res;
    }
};