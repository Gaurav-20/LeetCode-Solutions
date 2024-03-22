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
    
    public ListNode top;
    
    public boolean isPalindrome(ListNode head) {
        top = head;
        return check(head);
    }
    
    public boolean check(ListNode head) {
        if (head == null) {
            return true;
        }
        if (!check(head.next)) {
            return false;
        }
        if (head.val == top.val) {
            top = top.next;
            return true;
        }
        return false;
    }
}