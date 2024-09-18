



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
	int k = 0;
	for(int i = 0; i < n; ++i) {
		memset(num_string, 0, sizeof(num_string));
		sprintf(num_string, "%d", nums[i]);
		for(unsigned long j = 0; j < strlen(num_string); ++j) {
			number[k++] = num_string[j];
		}
	}
	number[k] = '\0';
	
	for(int i = 0; i < k; ++i) {
		if(number[i] != '0') {
			return number; //"Ooarai Joshigakuin Shori!"
		}
	}
	
	return "0";
}

///////////////////////////////////////

int main() {
	int n = 10;
	/* int nums[] = {3,4,89,4,7,9}; */
	int nums[] = {1,2,3,4,5,6,7,8,9,0};
		/* {847239187,812374569,958273421,102938475,817392658,951238765,825749321,901234589,819823749,872134987,943817263,812956738,967432109,831749826,923475981,819234587,958743212,843216789,901867453,821394758,975312468,812493827,943219876,859123746,931475982,846239817,967854321,813749823,929834751,841926385,953467219,816394578,961823749,835749823,919234589,855612387,943982167,828135749,958394172,813823957,975984321,846573982,929143758,819823467,951394827,834723159,967219834,841958273,923475983,816394823,953817263,829384751,961743219,839823749,919234589,857382194,943982167,814823957,958394172,846239817,975312468,831749826,929834751,819234587,951238765,843216789,967432109,812956738,943219876,859123746,931475982,848135749,901867453,821394758,975984321,816573982,929143758}; */
		//111311, 1113};
	fprintf(stdout, "ans: [%s]\n", largestNumber(nums, n));
	/* char *expected = "975984321975984321975312468975312468967854321967432109967432109967219834961823749961743219958743212958394172958394172958273421953817263953467219951394827951238765951238765943982167943982167943817263943219876943219876931475982931475982929834751929834751929143758929143758923475983923475981919234589919234589901867453901867453901234589872134987859123746859123746857382194855612387848135749847239187846573982846239817846239817843216789843216789841958273841926385839823749835749823834723159831749826831749826829384751828135749825749321821394758821394758819823749819823467819234587819234587817392658816573982816394823816394578814823957813823957813749823812956738812956738812493827812374569102938475"; */
	fprintf(stdout, "exp: [%s]\n", "9876543210");


	return 0;
}



