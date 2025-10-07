



import java.util.*;

class Pair implements Comparable<Pair> {
    int first, second;

    public Pair(int first, int second) {
        this.first = first; this.second = second;
    }

    @Override
    public int compareTo(Pair other) {
        return Integer.compare(this.first, other.first);
    }
}

class Solution {
    public static int inf      = Integer.MAX_VALUE >> 1;
    public static int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0}};

    public boolean isValid(int r, int c, int i, int j) {
        return i >= 0 && j >= 0 && i < r && j < c;
    }

    public int maximumSafenessFactor(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        if (grid[0][0] == 1 || grid[r - 1][c - 1] == 1) { return 0; }
        int[][] distances = new int[r][c];
        Deque<Integer> t = new ArrayDeque<>();
        boolean[] seen = new boolean[r*c];

        for (int i = 0; i < r; ++i) {
            Arrays.fill(distances[i], inf);
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) {
                    distances[i][j] = 0;
                    seen[i*c + j] = true;
                    t.push(i*c + j);
                }
            }
        }

        while (!t.isEmpty()) {
            int position = t.pollLast();
            int i = position / c, j = position % c;
            for (int[] dir: dirs) {
                int h = dir[0] + i, k = dir[1] + j;
                if (isValid(r, c, h, k) && !seen[h*c + k] && distances[h][k] == inf) {
                    distances[h][k] = distances[i][j] + 1;
                    t.push(h*c + k);
                    seen[h*c + k] = true;
                }
            }
        }


        PriorityQueue<Pair> u = new PriorityQueue<>();
        u.offer(new Pair(-distances[0][0], 0));
        Arrays.fill(seen, false);
        seen[0] = true;

        while (!u.isEmpty()) {
            Pair curr = u.poll();
            int currMax = -curr.first, position = curr.second;
            int i = position / c, j = position % c;

            if (i == r - 1 && j == c - 1) { return currMax; }
            for (int[] dir: dirs) {
                int h = dir[0] + i, k = dir[1] + j;
                if (isValid(r, c, h, k) && !seen[h*c + k] && grid[h][k] != 1) {
                    seen[h*c + k] = true;
                    u.offer(new Pair(-Math.min(distances[h][k], currMax), h*c + k));
                }
            }
        }

        return 0;
    }

    public int maximumSafenessFactor(List<List<Integer>> matrix) {
        int r = matrix.size(), c = matrix.get(0).size();
        int[][] grid = new int[r][c];
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                grid[i][j] = matrix.get(i).get(j);
            }
        }
        return maximumSafenessFactor(grid);
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
