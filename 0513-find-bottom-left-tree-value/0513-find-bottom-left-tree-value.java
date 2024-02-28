/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        // Doing a Right to Left BFS, so that the last element to be traversed is the result
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        TreeNode curr = root;
        while (queue.size() > 0) {
            curr = queue.poll();
            if (curr.right != null) {
                queue.add(curr.right);
            }
            if (curr.left != null) {
                queue.add(curr.left);
            }
        }
        return curr.val;
    }
}