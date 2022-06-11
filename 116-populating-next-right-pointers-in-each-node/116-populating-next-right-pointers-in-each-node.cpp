/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return root;
        }
        Node* head = root;
		while (head && head->left) {
			Node* x = head;
			while (x) {
				x->left->next = x->right;
				if (x->next) {
					x->right->next = x->next->left;
                }
				x = x->next;
            }
			head = head->left;
        }
		return root;
    }
};