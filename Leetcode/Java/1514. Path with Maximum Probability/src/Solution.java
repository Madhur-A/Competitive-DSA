



public class Solution {	
    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
		final int m = edges.length;
		double[] res = new double[n + 1];
		res[start_node] = 1.0;

		for(int i = 0, found = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				final int u = edges[j][0], v = edges[j][1];
				final double from = succProb[j];
				if(res[u] * from > res[v]) { res[v] = res[u] * from; found = 1; }
				if(res[v] * from > res[u]) { res[u] = res[v] * from; found = 1; }
			}
            if(found == 0) { break; }
		}
		

		return res[end_node];
    }
}

