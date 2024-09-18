



#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char number[1000];
char num_string[100];

int length(int num) { return floor(log(num)/log(10)) + 1; }

int cmp(long long a, long long b) {
	char p[100], q[100];
	memset(p, 0, sizeof(p)); memset(q, 0, sizeof(q));
	sprintf(p, "%lld%lld", a, b);
	sprintf(q, "%lld%lld", b, a);

	return strcmp(p, q);
}

void merge(int* prefix, int prefix_count, int* suffix, int suffix_count, int* res) {
	int i = 0, j = 0, k = 0;
	while(i < prefix_count && j < suffix_count) {
		if(cmp(prefix[i], suffix[j]) == 1) {
			res[k++] = prefix[i++];
		} else if(cmp(prefix[i], suffix[j]) == -1) {
			res[k++] = suffix[j++];
		} else {
			res[k++] = prefix[i++];
			res[k++] = suffix[j++];
		}
	}

	while(i < prefix_count) { res[k++] = prefix[i++]; }
	while(j < suffix_count) { res[k++] = suffix[j++]; }
}

void merge_sort(int* nums, int length) {
    if(length <= 1) { return; }
    int mid = length >> 2;

    int* left = nums;
	int *right = nums + mid;

    merge_sort(left, mid);
	merge_sort(right, length - mid);

    int* temp = (int*)malloc(length * sizeof(int));
    merge(left, mid, right, length - mid, temp);

    for(int i = 0; i < length; nums[i] = temp[i], i++);

    free(temp);
}

char* largestNumber(int* nums, int n) {
	merge_sort(nums, n);
	memset(number, 0, sizeof(number));
	int last = 0;
	for(int i = 0, k = 0; i < n; ++i) {
		sprintf(num_string, "%d", nums[i]);
		for(unsigned long j = 0; j < strlen(num_string); ++j) {
			number[k++] = num_string[j]; last++;
		}
	}
	number[last] = '\0';

	return number[0] == '0' ? "0" : number; //"Ooarai Joshigakuin Shori!"
}
