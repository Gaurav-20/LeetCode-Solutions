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
    public ListNode doubleIt(ListNode head) {
        int carry = doubleList(head);
        if (carry == 0) {
            return head;
        }
        ListNode newHead = new ListNode(carry);
        newHead.next = head;
        return newHead;
    }

    int doubleList(ListNode head) {
        if (head.next == null) {
            int val = head.val * 2;
            if (val >= 10) {
                head.val = val % 10;
                return val / 10;
            }
            head.val = val;
            return 0;
        }
        int carry = doubleList(head.next);
        int val = head.val * 2 + carry;
        if (val >= 10) {
            head.val = val % 10;
            return val / 10;
        }
        head.val = val;
        return 0;
    }
}