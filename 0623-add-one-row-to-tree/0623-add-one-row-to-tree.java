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
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, null);
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int currDepth = 0;
        while (!queue.isEmpty()) {
            currDepth += 1;
            int size = queue.size();
            while (size-- > 0) {
                TreeNode curr = queue.poll();
                if (currDepth == depth - 1) {
                    TreeNode newLeft = new TreeNode(val, curr.left, null);
                    TreeNode newRight = new TreeNode(val, null, curr.right);
                    curr.left = newLeft;
                    curr.right = newRight;
                }
                if (curr.left != null) {
                    queue.offer(curr.left);
                }
                if (curr.right != null) {
                    queue.offer(curr.right);
                }
            }
        }
        return root;
    }
}