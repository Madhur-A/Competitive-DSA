



import java.util.*;

class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;

        int minSoFar = prices[0], res = 0;
        for (int i = 0; i < n; ++i) {
            res = Math.max(res, prices[i] - minSoFar);
            minSoFar = Math.min(minSoFar, prices[i]);
        }

        return res;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
