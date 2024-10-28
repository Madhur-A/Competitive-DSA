



#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int trap(int* height, int n) {
    int left = 0, right = n - 1;
    int left_height = INT_MIN, right_height = INT_MIN;
    int ans = 0;
    while(left < right) {
        left_height = fmax(left_height, height[left]);
        right_height = fmax(right_height, height[right]);
        if(right_height > left_height) {
            ans = ans + (left_height - height[left++]);
        } else {
            ans = ans + (right_height - height[right--]);
        }
    }

    return ans;
}
