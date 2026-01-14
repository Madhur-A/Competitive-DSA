



#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using i64 = long long;
using a_tree =
    __gnu_pbds::tree<std::pair<i64, int>, __gnu_pbds::null_type,
                     std::less<std::pair<i64, int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

int main() {
    int n = 0, q = 0;
    std::cin >> n >> q;

    a_tree st;
    int i = 0, num = 0;
    std::vector<i64> nums(n);
    while(i < n) {
        std::cin >> num;
        nums[i++] = num;
        st.insert(std::make_pair(num, i));
    }

    int index = 0, value = 0;
    int left = 0, right = 0;
    while(q--) {
        char t;
        std::cin >> t;
        if (t == '!') {
            std::cin >> index >> value;
            st.erase(std::make_pair(nums[index - 1], index));
            nums[index - 1] = value;
            st.insert(std::make_pair(nums[index - 1], index));
        } else {
            std::cin >> left >> right;
            std::cout << st.order_of_key(std::make_pair(right, INT_MAX)) - st.order_of_key(std::make_pair(left - 1, INT_MAX)) << " ";
        }
    }
    std::cout << '\n';

    return 0;
}
