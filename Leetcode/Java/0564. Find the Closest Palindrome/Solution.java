



import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;

public class Solution {
	public class Pair<T extends Comparable<T>> implements Comparable<Pair<T>> {
		T first, second;
		public Pair(T first, T second) { this.first = first; this.second = second; }
		@Override
		public int compareTo(Pair<T> rhs) {
            final int res = first.compareTo(rhs.first);
            return res == 0 ? second.compareTo(rhs.second) : res;
        }
	}

	public boolean isPalindrome(long number) {
		long res = 0, curr = number;
		while(curr > 0) {
			res = 10 * res + (curr % 10);
			curr = curr / 10;
		}
		return res == number;
	}

	public long power(long count, long res) { return (count <= 0) ? res : power(count - 1, res * 10L); }

	public long reverseNumber(long number) {
		long res = 0L, curr = number;
		while(curr > 0) { res = res * 10 + (curr % 10); curr = curr / 10; }
		return res;
	}

	public long reverseAndFold(long number, int offset) {
		if(number > 16) {
	        int len = (int) (Math.floor(Math.log10(number)) + 1);
	        int mid = len >> 1;

	        long div = power(mid, 1);
	        long res = (number / div) + Long.valueOf(offset);

	        return res * div + (((len & 1) == 1) ? reverseNumber(res / 10) : reverseNumber(res));
		}
        return number + offset;
	}

	public String nearestPalindromic(String num) {
		final long number = Long.valueOf(num);
		PriorityQueue<Pair<Long>> t = new PriorityQueue<Pair<Long>>();
		Set<Long> seen = new HashSet<>();

		t.add(new Pair<Long>(0L, number - 1));
		t.add(new Pair<Long>(0L, number + 1));

		final int offsets[] = {-1, 0, 1};

		while(! t.isEmpty()) {
			Pair<Long> popped = t.poll();
			long diffs = popped.first, value = popped.second;
			if(value != number && isPalindrome(value)) { return String.valueOf(value); }
			if(! seen.contains(value)) {
				seen.add(value);
				for(int offset: offsets) {
					long res = reverseAndFold(value, offset);
					if(! seen.contains(res)) {
						t.add(new Pair<Long>(Math.abs(number - res), res));
					}
				}
			}
		}
		return "FAILURE: Shouldn't Arrive Here!";
	}
}
