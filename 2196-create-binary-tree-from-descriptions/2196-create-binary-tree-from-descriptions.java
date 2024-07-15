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
    public TreeNode createBinaryTree(int[][] descriptions) {
        int len = descriptions.length;
        if (len == 0) {
            return null;
        }
        Map<Integer, TreeNode> intToNodeMap = new HashMap<>();
        Map<TreeNode, Boolean> isChild = new HashMap<>();
        for (int i = 0; i < len; i++) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            if (intToNodeMap.get(parent) == null) {
                intToNodeMap.put(parent, new TreeNode(parent));
            }
            if (intToNodeMap.get(child) == null) {
                intToNodeMap.put(child, new TreeNode(child));
            }
            TreeNode parentNode = intToNodeMap.get(parent);
            TreeNode childNode = intToNodeMap.get(child);
            isChild.put(childNode, true);
            if (isLeft == 1) {
                parentNode.left = childNode;
            } else {
                parentNode.right = childNode;
            }
        }
        for (TreeNode node : intToNodeMap.values()) {
            if (isChild.get(node) == null) {
                return node;
            }
        }
        return null;
    }
}