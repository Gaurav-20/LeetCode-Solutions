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
    int remove(ListNode* head, int n) {
        if (head == nullptr) {
            return 1;
        }
        int x1 = remove(head->next, n);
        if (x1 == n + 1) {
            head->next = head->next->next;
        }
        return x1 + 1;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr && n == 1) {
            head = nullptr;
            return head;
        }
        if (remove(head, n) == n + 1) {
            head = head->next;
        }
        return head;
    }
};