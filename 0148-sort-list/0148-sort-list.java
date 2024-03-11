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
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        // Create two sub linked lists
        ListNode middle = getMiddle(head);
        ListNode nextToMiddle = middle.next;
        middle.next = null;
        ListNode leftSubList = sortList(head);
        ListNode rightSubList = sortList(nextToMiddle);
        return sortedMerge(leftSubList, rightSubList);
    }
    
    public ListNode getMiddle(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    
    public ListNode sortedMerge(ListNode left, ListNode right) {
        ListNode result = new ListNode(-1);
        ListNode curr = result;
        while (left != null && right != null) {
            if (left.val < right.val) {
                curr.next = left;
                left = left.next;
            } else {
                curr.next = right;
                right = right.next;
            }
            curr = curr.next;
        }
        if (left != null) {
            curr.next = left;
        } else {
            curr.next = right;
        }
        return result.next;
    }
}