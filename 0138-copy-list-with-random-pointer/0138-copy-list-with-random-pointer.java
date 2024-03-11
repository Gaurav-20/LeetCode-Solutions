/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        insertCopyNodes(head);
        connectRandomPtrs(head);
        return splitOriginalAndCopyList(head);
    }
    
    public void insertCopyNodes(Node head) {
        if (head == null) {
            return;
        }
        Node temp = head;
        while (temp != null) {
            Node copyNode = new Node(temp.val);
            copyNode.next = temp.next;
            temp.next = copyNode;
            temp = temp.next.next;
        }
    }
    
    public void connectRandomPtrs(Node head) {
        if (head == null) {
            return;
        }
        Node temp = head;
        while (temp != null) {
            if (temp.random != null) {
                temp.next.random = temp.random.next;
            } else {
                temp.next.random = null;
            }
            temp = temp.next.next;
        }
    }
    
    public Node splitOriginalAndCopyList(Node head) {
        Node dummy = new Node(-1);
        Node result = dummy;
        Node temp = head;
        while (temp != null) {
            result.next = temp.next;
            result = result.next;
            temp.next = temp.next.next;
            temp = temp.next;
        }
        return dummy.next;
    }
}