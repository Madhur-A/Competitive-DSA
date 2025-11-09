



import java.util.*;

class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length, first = days[0], last = days[n - 1];
        // indeed, it could be solved via one-dimensional dp, instead
        // of using two-dimensions, as done here; since the decision gets
        // taken on the basis of only one specific state's causal value,
        // viz., dp(i, 0).
        int[][] dp = new int[last + 1][3];
        boolean[] visited = new boolean[last + 1];

        for (int i = 0; i < n; ++i) { visited[days[i]] = true; }

        dp[first][0] = costs[0]; dp[first][1] = costs[1]; dp[first][2] = costs[2];
        int s = 7, t = 30;

        for (int i = first + 1; i < last + 1; ++i) {
            dp[i][0] = dp[i - 1][0] + (visited[i] ? costs[0] : 0);
            dp[i][1] = i - s < 0 ? dp[i - 1][1] : Math.min(dp[i - s][0] + costs[1], dp[i][0]);
            dp[i][2] = i - t < 0 ? dp[i - 1][2] : Math.min(dp[i - t][0] + costs[2], dp[i][0]);
            dp[i][0] = Math.min(dp[i][0], Math.min(dp[i][1], dp[i][2]));
        }


        return Math.min(dp[last][0], Math.min(dp[last][1], dp[last][2]));
    }


    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
