



#include <set>
#include <vector>
#include <iterator>
#include <cstring>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

// this calls for additional data structure along-with segment tree.
// here, the segment tree works as an auxliary structure while a binary
// search tree (red-black tree, i.e. `std::set`) acts as the primary
// data-structure. please note that this construction resembles much of
// what `van Emde Boas Tree` or the `Link-Cut Tree` (highly inefficient,
// in this particular case) or any other data-structure which manages
// the `successors` along side (at least) logarithimic updates and
// retrievals.


using i64 = long long;

inline static int const INF = 1'000'000'000;

class seg_tree {
public:
    int n;
    std::vector<i64> t;
public:
    inline seg_tree(int const& n): n(n), t(4 * n) {
    }

    inline void update(int index, i64 value) {
        return update(0, 0, n - 1, index, value);
    }

    inline void update(int node, int start, int end, int index, i64 value) {
        if (start == end) {
            t[node] = value;
        } else {
            int const mid = start + ((end - start) >> 1);
            if (index <= mid) {
                update(2*node + 1, start, mid, index, value);
            } else {
                update(2*node + 2, mid + 1, end, index, value);
            }
            t[node] = std::min(t[2*node + 1], t[2*node + 2]);
        }
    }

    inline i64 find(int left, int right) {
        return find(0, 0, n - 1, left, right);
    }

    inline i64 find(int node, int start, int end, int left, int right) {
        if (right < start or end < left) { return INF; }
        if (left <= start and end <= right) { return t[node]; }
        int const mid = start + ((end - start) >> 1);
        return
            std::min(find(2*node + 1, start, mid, left, right),
                     find(2*node + 2, mid + 1, end, left, right));
    }
};

struct solution {
    inline static void solve() {
        int n = 0, q = 0;
        std::cin >> n >> q;
        std::vector<i64> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        std::set<std::pair<i64, int>> value_index;

        for (int i = 0; i < n; ++i) {
            value_index.emplace(nums[i], i);
        }

        // segment tree whose elements are next indices (if they exist) of nums[i]
        seg_tree st(n);

        for (int i = 0; i < n; ++i) {
            std::set<std::pair<i64, int>>::iterator found =
                value_index.upper_bound(std::make_pair(nums[i], i));
            if (found == value_index.end() or found->first != nums[i]) {
                st.update(i, INF);
            } else {
                st.update(i, found->second);
            }
        }

        int type = 0;
        i64 k = 0, u = 0;
        while (q--) {
            std::cin >> type >> k >> u;
            if (type == 1) {
                k = k - 1;
                if (nums[k] == u) { // pointless to update;
                    continue;
                }
                // remove old entry from from `value_index`
                std::set<std::pair<i64, int>>::iterator found =
                    value_index.find(std::make_pair(nums[k], k));
                int prev = 0, next = INF;
                std::set<std::pair<i64, int>>::iterator prev_found = found;
                std::set<std::pair<i64, int>>::iterator next_found = found;
                if (found != value_index.begin()) {
                    --prev_found;
                    if (prev_found->first == nums[k]) {
                        prev = prev_found->second;
                    }
                }
                ++next_found;
                if (next_found != value_index.end() and next_found->first == nums[k]) {
                    next = next_found->second;
                }

                if (prev) {
                    st.update(prev, next);
                }
                value_index.erase(found);

                // insert new entry in `value_index`
                nums[k] = u;
                std::set<std::pair<i64, int>>::iterator new_pos =
                    value_index.lower_bound(std::make_pair(nums[k], k));
                prev = 0, next = INF;
                prev_found = new_pos;

                if (new_pos != value_index.begin()) {
                    --prev_found;
                    if (prev_found->first == u) {
                        prev = prev_found->second;
                    }
                }
                if (new_pos != value_index.end() and new_pos->first == u) {
                    next = new_pos->second;
                }

                if (prev) {
                    st.update(prev, k);
                }
                st.update(k, next);
                value_index.insert(std::make_pair(u, k));
            } else {
                int const res = st.find(k - 1, u - 1);
                std::cout << (res > u - 1 ? "YES" : "NO") << '\n';
            }
        }
    }
};

int main() { solution::solve(); }
