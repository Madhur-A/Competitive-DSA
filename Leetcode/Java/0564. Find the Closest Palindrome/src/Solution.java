



import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.LinkedList;
import java.util.HashSet;

class Solution {
	public class Pair<T extends Comparable<T>> implements Comparable<Pair<T>> {
		T first, second;
		public Pair(T first, T second) { this.first = first; this.second = second; }
		@Override
		public int compareTo(Pair<T> rhs) {
			final int res = first.compareTo(rhs.first);
			return (res == 0) ? second.compareTo(rhs.second) : res;
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

	public long reverseAndFold(long number, long offset) {
		String numString = String.valueOf(number);
		int len = numString.length();
		int mid = ((len & 1) == 1) ? 1 + (len >> 1) : (len >> 1);
		String half = String.valueOf(Long.valueOf(numString.substring(0, mid)) + offset);
		if(half.length() < mid) { return Long.valueOf(number - 1); }
		String ralf = new StringBuilder(half).reverse().substring(((numString.length() & 1) == 1) ? 1 : 0);

		return Long.valueOf(half + ralf);
	}

	public String auxSixteen(String num) {
		final long number = Long.valueOf(num);
		PriorityQueue<Long>  t = new PriorityQueue<>();
		Set<Long> seen = new HashSet<>();
		t.add(number - 1); t.add(number + 1);
		while(! t.isEmpty()) {
			long popped = t.poll();
			if(popped != number && isPalindrome(popped)) { return String.valueOf(popped); }
			if(! seen.contains(popped)) {
				seen.add(popped);
				if(! seen.contains(popped + 1)) { t.add(popped + 1); }
				if(! seen.contains(popped - 1)) { t.add(popped - 1); }
			}
		}
		return "-1";
	}

	public String nearestPalindromic(String num) {
		final long number = Long.valueOf(num);
		if(number <= 16L) { return auxSixteen(num); }
		PriorityQueue<Pair<Long>> t = new PriorityQueue<Pair<Long>>();
		Set<Long> seen = new HashSet<>();

		t.add(new Pair<Long>(1L, number+1));
		t.add(new Pair<Long>(1L, number-1));
		int offsets[] = {-1, 0, 1};

		while(! t.isEmpty()) {
			Pair<Long> popped = t.poll();
			long value = popped.second;
			if(value < 0) { continue; }
			if(value != number && isPalindrome(value)) { return String.valueOf(value); }
			if(! seen.contains(value)) {
				seen.add(value);
				for(int offset: offsets) {
					long newNumber = reverseAndFold(value, offset);
					if(! seen.contains(newNumber)) {
						t.add(new Pair<Long>(Math.abs(newNumber - number), newNumber));
					}
				}
			}
		}

		return "-1";
	}
}
