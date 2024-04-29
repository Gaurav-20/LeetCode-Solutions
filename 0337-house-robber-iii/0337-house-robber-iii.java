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
    public int rob(TreeNode root) {
        int[] result = solve(root);
        return Math.max(result[0], result[1]);
    }
    
    public int[] solve(TreeNode root) {
        if (root == null) {
            return new int[2];
        }
        int leftSubTree[] = solve(root.left);
        int rightSubTree[] = solve(root.right);

        int result[] = new int[2];
        result[0] = root.val + leftSubTree[1] + rightSubTree[1];
        result[1] = Integer.max(leftSubTree[0], leftSubTree[1]) 
                    + Integer.max(rightSubTree[0], rightSubTree[1]);
        return result;
    }
}