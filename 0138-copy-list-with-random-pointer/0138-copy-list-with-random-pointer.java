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
        if (head == null) {
            return head;
        }
        Node copy = head;
        Map<Node, Node> map = new HashMap<>();
        while (copy != null) {
            map.put(copy, new Node(copy.val));
            copy = copy.next;
        }
        copy = head;
        while (copy != null) {
            Node copyNext = copy.next;
            Node copyRandom = copy.random;
            map.get(copy).next = map.get(copyNext); 
            map.get(copy).random = map.get(copyRandom);
            copy = copy.next;
        }
        return map.get(head);
    }
}