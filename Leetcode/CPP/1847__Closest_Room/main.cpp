



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
	inline static constexpr int const inf = 1'000'000'000;
public:
	int find_left(std::vector<std::vector<int>> const &sorted_rooms, int const &target) {
		int left = 0, right = sorted_rooms.size(), mid = 0;
		while(left < right) {
			mid = left + ((right - left) >> 1);
			if(sorted_rooms[mid][1] < target) {
				left  = mid + 1;
			} else {
				right = mid;
			}
		}
		return left;
	}

    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
		int const n = rooms.size();
		std::ranges::sort(rooms, [&](std::vector<int> const &a, std::vector<int> const &b) {
			return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
		});

		std::vector<int> res(queries.size(), -1);
		int index = 0, min_possible = inf, min_value = inf;
		for(std::vector<int> const &query: queries) {
			int const min_size = query[1], preferred = query[0];
			int const found = find_left(rooms, min_size);
			min_possible = inf;
			min_value = inf;
			for(int i = found; i < n; ++i) {
				int const diff = std::abs(preferred - rooms[i][0]);
				if(diff <= min_value) {
					if(diff == min_value) {
						min_possible = std::min(min_possible, rooms[i][0]);
					} else {
						min_possible = rooms[i][0];
					}
					min_value = diff;
				}
			}
			if(min_possible != inf) {
				res[index] = min_possible;
			}
			index += 1;
		}

		return res;
    }
};

int main() {
	std::vector<std::vector<int>> rooms = {{2,2},{1,2},{3,2}};
	std::vector<std::vector<int>> queries = {{3,1},{3,3},{5,2}};

	Solution sol;
	std::ranges::copy(sol.closestRoom(rooms, queries), std::ostream_iterator<int>(std::cout, " "));
	std::putc('\n', stdout);


	return 0;
}
