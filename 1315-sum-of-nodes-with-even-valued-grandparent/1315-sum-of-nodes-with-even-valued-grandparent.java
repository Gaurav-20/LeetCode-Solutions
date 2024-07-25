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
    // hasEGP -> has even valued grandparent
    // hasEP -> has even valued parent
    public int sumEvenGrandparent(TreeNode root) {
        return solve(root, false, false);
    }
    
    public int solve(TreeNode root, boolean hasEGP, boolean hasEP) {
        if (root == null) {
            return 0;
        }
        return (hasEGP ? root.val : 0)
            + solve(root.left, hasEP, root.val % 2 == 0)
            + solve(root.right, hasEP, root.val % 2 == 0);
    }
}