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
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return head;
        }
        ListNode odd = head;
        ListNode even = head.next;
        while (head != null && head.next != null) {
            ListNode next = head.next;
            head.next = next.next;
            head = next;
        }
        ListNode ptr = odd;
        while (ptr.next != null) {
            ptr = ptr.next;
        }
        ptr.next = even;
        return odd;
    }
}