



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int const mask = (1 << maximumBit) - 1;
        std::vector<int> res(nums.size());
        std::partial_sum(nums.begin(), nums.end(), res.rbegin(), std::bit_xor<int>());
        std::for_each(res.begin(), res.end(), [&](int &num){ num = num ^ mask; });
        return res;
    }
};

#include <ranges>

int main() {
    Solution sol;
    std::vector<int> nums = {0,1,1,3};
    int maximumBit = 2;
    std::vector<int> res = sol.getMaximumXor(nums, maximumBit);
    std::ranges::copy(res, std::ostream_iterator<int>(std::cout, " "));
    std::putc('\n', stdout);


    return 0;
}
