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
    public TreeNode balanceBST(TreeNode root) {
        List<TreeNode> sortedNodes = new ArrayList<>();
        inorder(root, sortedNodes);
        return balance(sortedNodes, 0, sortedNodes.size() - 1);
    }
    
    public void inorder(TreeNode root, List<TreeNode> sortedNodes) {
        if (root == null) {
            return;
        }
        inorder(root.left, sortedNodes);
        sortedNodes.add(root);
        inorder(root.right, sortedNodes);
    }
    
    public TreeNode balance(List<TreeNode> list, int low, int high) {
        if (low > high) {
            return null;
        }
        int mid = (low + high) / 2;
        TreeNode root = list.get(mid);
        root.left = balance(list, low, mid - 1);
        root.right = balance(list, mid + 1, high);
        return root;
    }
}