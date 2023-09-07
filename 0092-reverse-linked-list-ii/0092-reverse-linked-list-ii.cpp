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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 1; curr && i < left; i++) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* start = curr;
        ListNode* end = nullptr;
        for (int i = 1; curr and i <= right - left + 1; i++) {
            ListNode* next = curr->next;
            curr->next = end;
            end = curr;
            curr = next;
        }
        start->next = curr;
        if (prev) {
            prev->next = end;
        }
        else {
            head = end;
        }
        return head;
    }
};