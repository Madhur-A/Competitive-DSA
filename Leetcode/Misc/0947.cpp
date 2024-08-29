



#include <bits/stdc++.h>
#include <ranges>
#include <defines>

int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

using std::vector;
using namespace av;

struct merge_find {
private:
	std::vector<int> roots, depths;
public:
	inline merge_find(int const &n): roots(n + 10), depths(n + 10) {
		std::iota(roots.begin(), roots.end(), 0);
	}

	inline int find(int const &i) {
		return roots[i] == i ? i : roots[i] = find(roots[i]);
	}

	inline void merge(int const &u, int const &v) {
		int const u_root = find(u), v_root = find(v);
		if(u_root != v_root) {
			int const u_depth = depths[u_root], v_depth = depths[v_root];
			if(u_depth < v_depth) {
				roots[u_root] = v_root;
				depths[v_root] += depths[u_root];
			} else {
				roots[v_root] = u_root;
				depths[u_root] += depths[v_root];
			}			
		}
	}
};


class Solution {
public:
    inline static
	int removeStones(vector<vector<int>>& stones) {
		int const n = stones.size(), m = std::ranges::max(stones | std::views::join);
		// println("max found element is", m);
		merge_find ufo(m + m + 1);
		std::unordered_set<int> seen;
		for(std::vector<int> const &stone: stones) {
			ufo.merge(stone[0], stone[1] + m + 1);
		}

		for(std::vector<int> const &stone: stones) {
			seen.insert(ufo.find(stone[0]));
		}
		
		return n - seen.size();
    }	
};

int main() {
	std::vector<std::vector<int>> stones1 = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
	std::vector<std::vector<int>> stones2 = {{0,0},{0,2},{1,1},{2,0},{2,2}};
	std::vector<std::vector<int>> stones3 = {{0,0}};
	
	av::println(Solution::removeStones(stones1));
	av::println(Solution::removeStones(stones2));
	av::println(Solution::removeStones(stones3));


	return 0;
}
