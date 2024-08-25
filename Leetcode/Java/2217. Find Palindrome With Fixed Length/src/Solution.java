



import java.util.HashMap;
import java.util.Map;

public class Solution {
	public Map<Long, Long> past = new HashMap<>();

	public long power(int count, long res) {
		return (count == 0) ? res : power(count - 1, 10L * res);
	}

	public long reverseNumber(long number) {
		long res = 0L, curr = number;
		while(curr > 0) { res = res * 10L + (curr % 10); curr = curr / 10; }
		return res;
	}

	public long getKthPalindrome(int len, long k) {
		if(! past.containsKey(k)) {
			int mid = (len >> 1) - (((len & 1) == 1) ? 0 : 1);
			final long left = power(mid, 1L), right = power(mid + 1, 1L);
			final long base = ((len & 1) == 1) ? left : right;
			final long sffx = ((len & 1) == 1) ? 10L  : 1L;
			long res = -1L;
			if(k <= right - left) {
				long num = left + k - 1;
				res = num * base + reverseNumber(num / sffx);
			}
			past.put(k, res);
		}
		return past.get(k);
	}

    public long[] kthPalindrome(int[] queries, int intLength) {
    	long buffer[] = new long[queries.length];

    	for(int i = 0; i < queries.length; ++i) {
    		buffer[i] = getKthPalindrome(intLength, queries[i]);
    	}

    	return buffer;
    }
}