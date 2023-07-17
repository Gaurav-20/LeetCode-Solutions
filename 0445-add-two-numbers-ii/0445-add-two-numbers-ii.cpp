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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* temp = l1;
        while (temp != nullptr) {
            s1.push(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while (temp != nullptr) {
            s2.push(temp->val);
            temp = temp->next;
        }
        ListNode* res = nullptr;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int digit1 = !s1.empty() ? s1.top() : 0;
            int digit2 = !s2.empty() ? s2.top() : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            newNode->next = res;
            res = newNode;
            
            if (!s1.empty()) {
                s1.pop();
            }
            if (!s2.empty()) {
                s2.pop();
            }
        }
        return res;
    }
};