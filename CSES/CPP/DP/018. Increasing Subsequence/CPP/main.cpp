



#include <vector>
#include <iostream>

struct solution {
    inline static int find_left(std::vector<int> const& nums, int const& target) {
        int left = 0, right = nums.size(), mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    inline static void solve(std::vector<int> const& nums) {
        int const n = nums.size();
        std::vector<int> curr;
        curr.push_back(nums[0]);

        for (int i = 1; i < n; ++i) {
            if (nums[i] > curr.back()) {
                curr.push_back(nums[i]);
            } else {
                curr[find_left(curr, nums[i])] = nums[i];
            }
        }

        std::cout << curr.size() << '\n';
    }

    inline static void solve() {
        int n = 0;
        std::cin >> n;
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) { std::cin >> nums[i]; }

        solve(nums);
    }
};

int main() { solution::solve(); }
