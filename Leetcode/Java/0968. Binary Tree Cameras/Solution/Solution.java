



import java.util.*;

class Solution {
    public int minCameraCover(TreeNode root) {
        // somewhat reminiscent of graph-colouring

        // consider this:
        // given a special kind of dye, which, when applied
        // to a binary tree node, can propagate towards the node's
        // parent and its children. then, how many distinct colours
        // are needed to completely colour a given binary tree, so
        // that no two adjacent colours are same.

        int ans = 0;
        TreeNode curr = root, last = null;

        ArrayDeque<TreeNode> t = new ArrayDeque<>();
        Map<TreeNode, Integer> seen = new HashMap<>();

        while (!t.isEmpty() || curr != null) {
            if (curr != null) {
                t.offerFirst(curr);
                curr = curr.left;
            } else {
                TreeNode top = t.peek();
                if (top.right != null && top.right != last) {
                    curr = top.right;
                } else {
                    int left = seen.getOrDefault(top.left, 2), right = seen.getOrDefault(top.right, 2);
                    if (left == 0 || right == 0) {
                        ans += 1; seen.put(top, 1); // coloured
                    } else if (left == 1 || right == 1) {
                        seen.put(top, 2); // already coloured
                    } else {
                        seen.put(top, 0); // needs colouring
                    }
                    last = t.pollFirst();
                }
            }
        }

        int res = seen.getOrDefault(root, 0);
        return res == 0 ? ans + 1 : ans;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
