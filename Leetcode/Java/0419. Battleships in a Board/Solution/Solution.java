



import java.util.*;

class Solution {
    public int countBattleships(char[][] grid) {
        int r = grid.length, c = grid[0].length, res = 0;

        for (int i = 0; i < r; ++i) {
            char[] row = grid[i]; // cutting double indexing, thereby initializing cache-warmup
            for (int j = 0; j < c; ++j) {
                if (row[j] == 'X' && (i == 0 || grid[i - 1][j] != 'X') && (j == 0 || row[j - 1] != 'X')) { ++res; }
                // note that `res += (condition) ? 1 : 0;` adds overhead in Java, as compiler Java compiler
                // can't determine branches deterministically.
            }
        }

        return res;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
