



import java.util.*;

class Solution {
    public int minCost(int[] startPos, int[] homePos, int[] rowCosts, int[] colCosts) {
        int r = rowCosts.length, c = colCosts.length, totalCost = 0;
        int i = startPos[0], j = startPos[1], h = homePos[0], k = homePos[1];

        if (i > h) { while (i > 0 && i != h) { totalCost += rowCosts[i - 1]; i = i - 1; } }
        if (i < h) { while (i < r && i != h) { totalCost += rowCosts[i + 1]; i = i + 1; } }

        if (j > k) { while (j > 0 && j != k) { totalCost += colCosts[j - 1]; j = j - 1; } }
        if (j < k) { while (j < c && j != k) { totalCost += colCosts[j + 1]; j = j + 1; } }

        return totalCost;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
