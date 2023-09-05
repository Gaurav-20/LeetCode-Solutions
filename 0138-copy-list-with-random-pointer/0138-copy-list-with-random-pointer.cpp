/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node* copy = head;
        unordered_map<Node*, Node*> mp;

        while (copy) {
            mp[copy] = new Node(copy->val);
            copy = copy->next;
        }
        copy = head;
        while(copy) {
            Node* copyNext = copy->next;
            Node* copyRandom = copy->random;
            mp[copy]->next = mp[copyNext]; 
            mp[copy]->random = mp[copyRandom];
            copy = copy->next;
        }
        return mp[head];
    }
};