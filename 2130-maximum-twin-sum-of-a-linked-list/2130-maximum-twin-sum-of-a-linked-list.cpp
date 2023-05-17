/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while (temp) {
            st.push(temp->val);
            temp = temp->next;
        }
        int res = 0;
        while (st.size()) {
            res = max(res, st.top() + head->val);
            head = head->next;
            st.pop();
        }
        return res;
    }
};