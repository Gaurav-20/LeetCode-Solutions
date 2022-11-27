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
    ListNode* solve(ListNode* head, int& maxVal) {
        if (head == nullptr) {
            return head;
        }
        ListNode* res = solve(head->next, maxVal);
        if (head->val < maxVal) {
            if (head->next != nullptr) {
                head->val = head->next->val;
                head->next = head->next->next;
            }
        }
        maxVal = max(maxVal, head->val);
        return res;
    }
    
    ListNode* removeNodes(ListNode* head) {
        int maxVal = -1;
        solve(head, maxVal);
        return head;
    }
};