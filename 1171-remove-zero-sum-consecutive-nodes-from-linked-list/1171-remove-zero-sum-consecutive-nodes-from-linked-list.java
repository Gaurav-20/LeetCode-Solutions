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
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = head;
        while (slow != null) {
            int sum = 0;
            fast = slow;
            ListNode end = null;
            while (fast != null) {
                sum += fast.val;
                if (sum == 0) {
                    end = fast; // Don't break, to maximize the window
                }
                fast = fast.next;
            }
            if (end != null) {
                if (slow == head) {
                    head = end.next; // If head is in delete window move head
                }
                prev.next = end.next; // Delete the window and skip it
                slow = end.next;
            } else {
                prev = slow;
                slow = slow.next;
            }
        }
        return head;
    }
}