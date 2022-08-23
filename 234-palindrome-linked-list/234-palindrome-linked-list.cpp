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
    bool check(ListNode* head, ListNode* &top) {
        if (head == nullptr) {
            return true;
        }
        if (!check(head->next, top)) {
            return false;
        }
        if (head->val == top->val) {
            top = top->next;
            return true;
        }
        return false;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* top = head;
        return check(head, top);
    }
};