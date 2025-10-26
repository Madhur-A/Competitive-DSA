



import java.util.*;

class Solution {
    public TreeNode copied(TreeNode node) {
        if (node == null) { return null; }
        return new TreeNode(node.val, copied(node.left), copied(node.right));
    }

    public List<TreeNode> generateTrees(int n) {
        if (n == 0) return new ArrayList<>();

        List<TreeNode> nullList = new ArrayList<>();
        List<TreeNode>[][] dp = new List[n + 2][n + 2];

        nullList.add(null);
        for (int i = 1; i < n + 2; ++i) { Arrays.fill(dp[i], nullList); }

        for (int len = 1; len < n + 1; ++len) {
            for (int left = 1; left < n - len + 2; ++left) {
                int right = left + len - 1;
                dp[left][right] = new ArrayList<>();
                for (int mid = left; mid < right + 1; ++mid) {
                    List<TreeNode> leftSub = dp[left][mid - 1], rightSub = dp[mid + 1][right];
                    for (TreeNode leftNode: leftSub) {
                        for (TreeNode rightNode: rightSub) {
                            dp[left][right].add(new TreeNode(mid, copied(leftNode), copied(rightNode)));
                        }
                    }
                }
            }
        }

        return dp[1][n];
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
