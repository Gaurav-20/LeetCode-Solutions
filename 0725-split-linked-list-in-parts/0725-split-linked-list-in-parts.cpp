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
    int countNodes(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = countNodes(head);
        int nodesPerPart = n / k;
        int partsWithExtraNodes = n % k;
        ListNode* currTail = head;
        ListNode* currHead = head;
        int currNodes = 0;
        vector<ListNode*> res;
        for (int i = 1; i <= n; i++) {
            currNodes++;
            if (currNodes == nodesPerPart + (partsWithExtraNodes > 0)) {
                res.push_back(currHead);
                ListNode* nextHead = currTail->next;
                currTail->next = nullptr;
                partsWithExtraNodes--;
                currNodes = 0;
                currHead = nextHead;
                currTail = nextHead;
                continue;
            }
            currTail = currTail->next;
        }
        while (res.size() < k) {
            res.push_back(nullptr);
        }
        return res;
    }
};