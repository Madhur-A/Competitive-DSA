



import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.TreeMap;

public class Solution {
	public static List<List<Long>> splitPainting(int[][] segments) {
		TreeMap<Integer, Long> seen = new TreeMap<>();
		
		for(int[] segment: segments) {
			final int start = segment[0], end = segment[1];
			final long value = segment[2];
			seen.merge(start, value, (prevValue, currValue) -> prevValue + currValue);
			seen.merge(end, -value, (prevValue, currValue) -> prevValue + currValue);
		}

		List<List<Long>> res = new ArrayList<>();

		int start = 0;
		long cumulativeSum = 0L;
		for(int end: seen.keySet()) {
			if(cumulativeSum > 0) {
				res.add(new ArrayList<Long>(Arrays.asList(Long.valueOf(start), Long.valueOf(end), cumulativeSum)));
			}
			cumulativeSum += seen.get(end);
			start = end;
		}

		return res;
	}
}

