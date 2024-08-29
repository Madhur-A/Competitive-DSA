



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
			} else {
				roots[v_root] = u_root;
				depths[u_root] += 1;
			}			
		}
	}

	inline int count_unique_parents(vector<vector<int>>& stones) {
		std::unordered_set<int> seen;
		for(std::vector<int> const &stone: stones) {
			seen.insert(this->find(stone[0]));
		}
		return stones.size() - seen.size();
	}
};

#include <ranges>

class Solution {
public:
    inline static
	int removeStones(vector<vector<int>>& stones) {
		int const m = std::ranges::max(stones | std::views::join);
		merge_find ufo(m + m + 1);

		for(std::vector<int> const &stone: stones) {
			ufo.merge(stone[0], stone[1] + m + 1);
		}
		
		return ufo.count_unique_parents(stones);
    }	
};

