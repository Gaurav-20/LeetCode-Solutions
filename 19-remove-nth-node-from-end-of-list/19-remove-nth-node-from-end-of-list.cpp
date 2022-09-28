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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        // Move fast pointer ahead by n, so that the diff between slow and fast is n
        // so when fast is at the end, slow would be at the nth node from last
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (!fast) {
            // If fast is already at the end, it means nth node from last is the head
            return head->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};