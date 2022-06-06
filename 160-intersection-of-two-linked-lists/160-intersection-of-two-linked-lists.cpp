/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        while (true) {
            if (ptrA == ptrB) {
                return ptrA;
            }
            ptrA = ptrA->next;
            ptrB = ptrB->next;
            if (ptrA == nullptr) {
                ptrA = headA;
            }
            if (ptrB == nullptr) {
                ptrB = headB;
            }
            if (ptrA == headA && ptrB == headB) {
                return nullptr;
            }
        }
        return nullptr;
    }
};