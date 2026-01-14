




#include <bits/stdc++.h>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using i64 = long long;

struct node {
public:
    int start, finish, mid;
    node* left; node* right; node* parent;
    int node_count;
public:
    inline node(int const &start, int const &finish, node* parent): start(start), finish(finish), mid(start + ((finish - start) >> 1)), parent(parent) {
        if(start != finish) {
            left  = new node(start, mid, this);
            right = new node(mid + 1, finish, this);
            node_count = left->node_count + right->node_count;
        } else { node_count = 1; }
    }

    inline void erase(int const &count, std::vector<i64> &res, std::vector<i64> const &nums) {
        if(count <= node_count) {
            node_count -= 1;
            if(start == finish) {
                res.push_back(nums[start]);
            } else if(left->node_count > count) {
                left->erase(count, res, nums);
            } else {
                right->erase(count - left->node_count, res, nums);
            }
        }
    }
};

int main() {
    int n = 0, i = 0, j = 0;
    std::cin >> n;
    std::vector<i64> nums(n);
    int num = 0;
    while(i < n) {
        std::cin >> num;
        nums[i++] = num;
    }

    node st(0, n - 1, nullptr);
    std::vector<i64> res;

    while(j < n) {
        std::cin >> num;
        st.erase(num - 1, res, nums);
        j += 1;
    }

    std::ranges::copy(res, std::ostream_iterator<i64>(std::cout, " "));
    std::cout << '\n';


    return 0;
}
