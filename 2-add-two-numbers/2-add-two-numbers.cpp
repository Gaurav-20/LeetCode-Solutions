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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
        if (l1 != nullptr || l2 != nullptr) {
            int val1 = (l1 == nullptr) ? 0 : l1->val;
            int val2 = (l2 == nullptr) ? 0 : l2->val;
            int currVal = val1 + val2 + carry;
            ListNode* currNode = new ListNode(currVal % 10);
            currNode->next = addTwoNumbers(
                                            l1 != nullptr ? l1->next : nullptr, 
                                            l2 != nullptr ? l2->next : nullptr,
                                            currVal / 10);
            return currNode;
        } else {
            if (carry > 0) {
                return new ListNode(carry);
            }
        }
        return nullptr;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);
    }
};