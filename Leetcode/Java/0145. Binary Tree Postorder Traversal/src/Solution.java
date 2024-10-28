



import java.util.ArrayList;
import java.util.List;

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


public class Solution {
    List<Integer> res;

    public void rx(TreeNode node) {
        if(node != null) {
            rx(node.left);
            rx(node.right);
            res.add(node.val);
        }
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        res = new ArrayList<>();
        rx(root);
        return res;
    }
}
