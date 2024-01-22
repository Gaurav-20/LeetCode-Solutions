/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    public static String SPLIT = ",";
    public static String END = "#";

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            return END;
        } else {
            String left = serialize(root.left);
            String right = serialize(root.right);
            StringBuilder builder = new StringBuilder();
            builder.append(root.val).append(SPLIT).append(left).append(SPLIT).append(right);
            return builder.toString();
        }
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        Queue<String> treeNodes = new LinkedList<>();
        treeNodes.addAll(Arrays.asList(data.split(SPLIT)));
        return helper(treeNodes);
    }
    
    public TreeNode helper(Queue<String> treeNodes) {
        String currNode = treeNodes.poll();
        if (currNode.equals(END)) {
			return null;
		} else {
            TreeNode newNode = new TreeNode(Integer.parseInt(currNode));
            newNode.left = helper(treeNodes);
            newNode.right = helper(treeNodes);
            return newNode;
        }
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;