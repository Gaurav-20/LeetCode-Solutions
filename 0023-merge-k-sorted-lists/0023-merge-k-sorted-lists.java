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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) {
            return null;
        }
        PriorityQueue<ListNode> pq = new PriorityQueue<>(lists.length, new ListNodeComparator());
        for (int i = 0; i < lists.length; i++) {
            if (lists[i] != null) {
                pq.add(lists[i]);
            }
        }
        ListNode head = null;
        ListNode prev = null;
        ListNode curr = null;
        while (!pq.isEmpty()) {
            curr = pq.poll();
            if (head == null) {
                head = curr;
            }
            if (prev != null) {
                prev.next = curr;
            }
            if (curr.next != null) {
                pq.add(curr.next);
            }
            prev = curr;
        }
        return head;
    }
}

class ListNodeComparator implements Comparator<ListNode> {
    @Override
    public int compare(ListNode l1, ListNode l2) {
        return l1.val - l2.val;
    }
}