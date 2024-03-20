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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode start = list1, end = list1;
        for (int i = 0; i <= b; i++) {
            if (i < a - 1) {
                start = start.next;
            }
            end = end.next;
        }
        start.next = list2;
        while (start.next != null) {
            start = start.next;
        }
        start.next = end;
        return list1;
    }
}