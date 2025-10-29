



import java.util.*;

class Solution {
    public int res = 0, maxTime = 0;

    public boolean[] visited;
    public int[] distToZero;

    public void dfs(List<int[]>[] g, int[] values, int node, int totalTime, int currValue) {
        if (node == 0) { res = Math.max(res, currValue); }

        for (int[] child: g[node]) {
            int nextNode  = child[0], childTime = child[1];
            int timeTaken = totalTime + childTime;
            int newValue  = currValue + (visited[nextNode] ? 0 : values[nextNode]);

            if (timeTaken + distToZero[nextNode] <= maxTime) { // early pruning courtesy of Dijkstra
                boolean prevVisited = visited[nextNode];
                visited[nextNode] = (visited[nextNode] ^ !visited[nextNode]);
                dfs(g, values, nextNode, timeTaken, newValue);
                visited[nextNode] = prevVisited;
            }
        }
    }

    public int[] dijkstra(List<int[]>[] g, int n) {
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE >> 1);
        dist[0] = 0;

        PriorityQueue<int[]> t = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        t.offer(new int[]{0, 0});

        while (!t.isEmpty()) {
            int[] curr = t.poll();
            int currNode = curr[0], currTime = curr[1];
            if (currTime > dist[currNode]) continue;

            for (int[] child: g[currNode]) {
                int childNode = child[0], childTime = child[1];
                if (dist[childNode] > currTime + childTime) {
                    dist[childNode] = currTime + childTime;
                    t.offer(new int[]{childNode, dist[childNode]});
                }
            }
        }
        return dist;
    }

    public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
        int n = values.length;
        this.maxTime = maxTime;

        List<int[]>[] g = new ArrayList[n];
        for (int i = 0; i < n; ++i) g[i] = new ArrayList<>();
        for (int[] e : edges) {
            int u = e[0], v = e[1], t = e[2];
            g[u].add(new int[]{v, t});
            g[v].add(new int[]{u, t});
        }

        distToZero = dijkstra(g, n);

        visited = new boolean[n];
        visited[0] = true;
        dfs(g, values, 0, 0, values[0]);

        return res;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
