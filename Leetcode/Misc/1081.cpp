



int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

class Solution {
public:
    std::string ans;
public:
    string smallestSubsequence(string s) {
        int const n = s.length();
        std::vector<int> last_indices(26), seen(26);

		for(int i = 0; i < n; ++i) {
			last_indices[s[i] - 'a'] = i;
		}

		for(int i = 0; i < n; ++i) {
            char const c = s[i];
            if(not seen[c - 'a']) {
				while(not ans.empty() and c < ans.back() and i < last_indices[ans.back()-'a']) {
					seen[ans.back() - 'a'] = 0;
					ans.pop_back();
				}
				ans.push_back(c);
				seen[c - 'a'] = 1;
			}
        }
        return ans;
    }
};
