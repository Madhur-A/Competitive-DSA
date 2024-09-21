



#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int jump(int* nums, int n) {
    int max_till_now = 0, index = 0, res = 0;
    for(int i = 0; i < n - 1; ++i) {
        max_till_now = fmax(max_till_now, nums[i] + i);
        if(index == i) {
            index = max_till_now;
            res += 1;
        }
    }
    return res;
}
