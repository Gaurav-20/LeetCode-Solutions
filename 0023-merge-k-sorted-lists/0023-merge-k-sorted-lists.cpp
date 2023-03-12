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

class Compare {
public:
    bool operator()(const ListNode* l1, const ListNode* l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (ListNode* node : lists) {
            if (node) {
                pq.push(node);
            }
        }
        if (pq.size() == 0) {
            return nullptr;
        }
        ListNode *temp, *head, *popped;
        popped = pq.top();
        pq.pop();
        head = popped;
        if (popped->next) {
            pq.push(popped->next);
        }
        temp = head;
        while (!pq.empty()) {
            popped = pq.top();
            pq.pop();
            temp->next = popped;
            temp = temp->next;
            if (popped->next) {
                pq.push(popped->next);
            }
        }
        return head;
    }
};