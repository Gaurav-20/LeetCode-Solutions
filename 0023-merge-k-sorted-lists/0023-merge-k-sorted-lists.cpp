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
    bool operator()(ListNode* l1, ListNode* l2) {
        return l1->val >= l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (auto list: lists) {
            if (list) {
                pq.push(list);
            }
        }
        ListNode* head = nullptr;
        ListNode* curr;
        ListNode* prev;
        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();
            if (head == nullptr) {
                head = curr;
            } else {
                prev->next = curr;
            }
            if (curr->next) {
                pq.push(curr->next);
            }
            prev = curr;
        }
        return head;
    }
};