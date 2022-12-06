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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* odd = head;
        if (odd->next == nullptr || odd->next->next == nullptr) {
            return head;
        }
        ListNode* even = head->next;
        while (head && head->next) {
            ListNode* nxt = head->next;
            head->next = nxt->next;
            head = nxt;
        }
        ListNode* p = odd;
        while (p->next) {
            p = p->next;
        }
        p->next = even;
        return odd;
    }
};