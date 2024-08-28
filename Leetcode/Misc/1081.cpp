



int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

class Solution {
public:
    inline static string smallestSubsequence(string s) {
		int const n = s.length();
		std::string ans;
		
		std::vector<int> indices(26), seen(26);

		for(int i = 0; i < n; ++i) { indices[i] = s[i] - 'a'; }
		for(int j = 0; j < n; ++j) {
			if(seen[s[j] - 'a']) { continue; }
			while(not ans.empty() and ans.back() > s[j] and j > indices[s[j] - 'a']) {
				seen[ans.back() - 'a'] = 0;
				ans.pop_back();
			}
			ans.push_back(s[j]);
			seen[s[j] - 'a'] = 1;
		}
		
		return ans;
	}
};
