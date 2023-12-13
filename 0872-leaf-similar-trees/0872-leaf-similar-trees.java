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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> rootList1 = new ArrayList<>();
        List<Integer> rootList2 = new ArrayList<>();
        inorderTraverse(root1, rootList1);
        inorderTraverse(root2, rootList2);
        return rootList1.equals(rootList2);
    }
    
    void inorderTraverse(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }
        inorderTraverse(root.left, list);
        if (root.left == null && root.right == null) {
            list.add(root.val);
        }
        inorderTraverse(root.right, list);
    }
}