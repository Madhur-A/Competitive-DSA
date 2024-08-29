



import java.util.*;

public class Solution {
	public class MergeFind {
		int roots[];
		int ranks[];
		MergeFind(int numberOfNodes) {
			this.roots = IntStream.range(0, numberOfNodes + 10).toArray();
			this.ranks = new int[numberOfNodes + 10];
		}

		int find(int i) {
			if(i != roots[i]) { roots[i] = find(roots[i]); }
			return roots[i];
		}

		void merge(int u, int v) {
			final int uRoot = find(u), vRoot = find(v);
			if(uRoot != vRoot) {
				final int uRank = ranks[uRoot], vRank = ranks[vRoot];
				if(uRank < vRank) {
					roots[uRoot] = vRoot;					
				} else {
					roots[vRoot] = uRoot;
					ranks[uRoot] = ranks[uRoot] + 1;
				}
			}
		}

		int get(int[][] stones) {
			Set<Integer> seen = new HashSet<>();
			for(int[] stone: stones) {
				seen.add(find(stone[0]));
			}
			return stones.length - seen.size();
		}
	}

    public int removeStones(int[][] stones) {
		final int maxVertex = Arrays.stream(stones).flatMapToInt(Arrays::stream).max().getAsInt();		
		MergeFind ufo = new MergeFind(maxVertex + maxVertex + 1);
		for(int[] stone: stones) { ufo.merge(stone[0], stone[1] + maxVertex + 1); }
		
		return ufo.get(stones);
    }
}

