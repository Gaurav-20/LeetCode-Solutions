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
        List<Integer> sortedArray = new ArrayList<>();
        inorder(root, sortedArray);
        return balance(sortedArray, 0, sortedArray.size() - 1);
    }
    
    public void inorder(TreeNode root, List<Integer> sortedArray) {
        if (root == null) {
            return;
        }
        inorder(root.left, sortedArray);
        sortedArray.add(root.val);
        inorder(root.right, sortedArray);
    }
    
    public TreeNode balance(List<Integer> list, int low, int high) {
        if (low > high) {
            return null;
        }
        int mid = (low + high) / 2;
        TreeNode root = new TreeNode(list.get(mid));
        root.left = balance(list, low, mid - 1);
        root.right = balance(list, mid + 1, high);
        return root;
    }
}