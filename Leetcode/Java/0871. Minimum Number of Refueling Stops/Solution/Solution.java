



import java.util.*;

class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int n = stations.length;
        long[] dp = new long[n + 1];

        dp[0] = startFuel;

        for (int i = 1; i < n + 1; ++i) {
            for (int j = i; j > 0 && stations[i - 1][0] <= dp[j - 1]; --j) {
                if (dp[j] >= dp[j - 1] + stations[i - 1][1]) { break; }
                dp[j] = dp[j - 1] + stations[i - 1][1];
            }
        }

        for (int i = 0; i < n + 1; ++i) {
            if (dp[i] > target - 1) { return i; }
        }

        return -1;
    }

    public static void main(String[] args) {
        System.out.println("------------------DONE------------------");
    }
}
