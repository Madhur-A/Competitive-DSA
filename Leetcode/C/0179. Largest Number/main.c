



#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char number[1000];
char num_string[100];

int length(int num) { return floor(log(num)/log(10)) + 1; }

int cmp(int a, int b) {
	long long p = a * pow(10, length(b) + 1) + b;
	long long q = b * pow(10, length(a) + 1) + a;
	fprintf(stdout, "[%lld] and [%lld]\n", p, q);
	return (p == q) ? 0 : (p < q) ? 1 : -1;
}

void merge(int* prefix, int prefix_count, int* suffix, int suffix_count, int* res) {
	int i = 0, j = 0, k = 0, cmp_res = 0;
	while(i < prefix_count && j < suffix_count) {
		cmp_res = cmp(prefix[i], suffix[j]);
		if(cmp_res == -1) {
			res[k++] = prefix[i++];
		} else if(cmp_res == 1) {
			res[k++] = suffix[j++];
		} else {
			res[k++] = prefix[i];
			i++; j++;
		}
	}

	while(i < prefix_count) { res[k++] = prefix[i++]; }
	while(j < suffix_count) { res[k++] = suffix[j++]; }
}

void merge_sort(int* nums, int length) {
    if(length <= 1) { return; }

    int mid = length / 2;
    int* left = nums, *right = nums + mid;

    merge_sort(left, mid);
    merge_sort(right, length - mid);

    int* temp = (int*)malloc(length * sizeof(int));
    merge(left, mid, right, length - mid, temp);

    for (int i = 0; i < length; i++) { nums[i] = temp[i]; }
    free(temp);
}

char* largestNumber(int* nums, int n) {
	merge_sort(nums, n);	
	memset(number, 0, sizeof(number));
	for(int i = 0, k = 0; i < n; ++i) {
		memset(num_string, 0, sizeof(num_string));
		sprintf(num_string, "%d", nums[i]);
		for(int j = 0; j < length(nums[i]); ++j) {
			number[k++] = num_string[j];
		}
	}
    
	return number;
}

int main() {
	int n = 2;
	int nums[] = {111311, 1113};
	fprintf(stdout, "ans: [%s]\n", largestNumber(nums, n));

	return 0;
}
