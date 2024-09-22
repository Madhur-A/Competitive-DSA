



#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

long get_next(long curr, long n) {
	long next = curr + 1, sigma = 0;
	while(curr <= n) {
		sigma += fmin(n - curr + 1, next - curr);
		next = next * 10;
		curr = curr * 10;
	}
	return sigma;
}

long find_kth_number(long n, long k) {
	long ans = 1, next = 0;
	k = k - 1;
	while(k) {
		next = get_next(ans, n);
		if(k >= next) {
			k = k - next;
			ans = ans + 1;
		} else {
			k = k - 1;
			ans = ans * 10;
		}
	}
	return ans;
}
