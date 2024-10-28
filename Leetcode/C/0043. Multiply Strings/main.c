



#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int pos[3000];
char res[3000];

char* multiply(char* num1, char* num2) {
    if(strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) { return "0"; }
    int len1 = strlen(num1), len2 = strlen(num2);
    memset(pos, 0, sizeof(pos));

    for(int i = len1 - 1; 0 <= i; --i) {
        for(int j = len2 - 1; 0 <= j; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + pos[p2];

            pos[p1] += sum / 10;
            pos[p2]  = sum % 10;
        }
    }

    int start = 0;
    while(start < len1 + len2 && pos[start] == 0) { ++start; }

    int x = 0;
    for(int i = start; i <= len1 + len2 - 1; ++i) {
        res[x++] = pos[i] + '0';
    }
    res[x] = '\0';

    return res;
}
