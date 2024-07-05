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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] result = new int[2];
        result[0] = result[1] = -1;
        if (head == null || head.next == null || head.next.next == null) {
            return result;
        }
        result[0] = 100000000;
        ListNode prv = head, cur = head.next, nxt = head.next.next;
        int counter = 0, criticalPoints = 0, firstCritical = -1, lastCritical = -1;
        while (nxt != null) {
            counter += 1;
            if ((prv.val < cur.val && nxt.val < cur.val) || (prv.val > cur.val && nxt.val > cur.val)) {
                criticalPoints += 1;
                if (firstCritical == -1) {
                    firstCritical = counter;
                }
                if (lastCritical != -1) {
                    result[0] = Math.min(result[0], counter - lastCritical);
                }
                lastCritical = counter;
                result[1] = Math.max(result[1], lastCritical - firstCritical);
            }
            prv = cur;
            cur = nxt;
            nxt = nxt.next;
        }
        return (criticalPoints >= 2) ? result : new int[] { -1, -1 };
    }
}