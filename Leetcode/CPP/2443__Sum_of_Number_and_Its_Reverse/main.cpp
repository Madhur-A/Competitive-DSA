




#include <bits/stdc++.h>

class Solution {
public:
    int rev(int num) {
        int res = 0;
        while(num) {
            res = 10 * res + (num % 10);
            num = num / 10;
        }
        return res;
    }

    bool sumOfNumberAndReverse(int num) {
        int left = num / 2;
        while(left <= num) {
            if(left + rev(left) == num) {
                return true;
            }
            left += 1;
        }
        return false;
    }
};


int main() {
    Solution sol;
    int num = 443;
    std::cout.setf(std::ios::boolalpha);
    std::cout << sol.sumOfNumberAndReverse(num) << '\n';


    return 0;
}

