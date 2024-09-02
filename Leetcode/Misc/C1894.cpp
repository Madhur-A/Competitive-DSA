



int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        std::vector<long> pfx(chalk.size()), nums(chalk.begin(), chalk.end());
        std::partial_sum(nums.begin(), nums.end(), pfx.begin());
        return ((k % pfx.back()) != 0) ? std::upper_bound(pfx.begin(), pfx.end(), (k % pfx.back())) - pfx.begin() : 0;
    }
};

