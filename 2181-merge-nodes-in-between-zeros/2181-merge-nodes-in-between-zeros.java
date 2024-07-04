/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode dummy = new ListNode(-1);
        ListNode temp = dummy;
        ListNode curr = head;
        int sum = 0;
        while (curr != null) {
            if (curr.val == 0) {
                if (sum != 0) {
                    ListNode newNode = new ListNode(sum);
                    temp.next = newNode;
                    temp = temp.next;
                    sum = 0;
                }
            } else {
                sum += curr.val;
            }
            curr = curr.next;
        }
        return dummy.next;
    }
}