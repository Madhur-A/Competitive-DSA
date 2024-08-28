



class Solution {
public:
    std::unordered_set<int> seen;
    std::string ans;
public:
    string smallestSubsequence(string s) {
        int const n = s.length();
        std::vector<int> g(26);
        for(int i = 0; i < n; ++i) { g[s[i]-'a'] = i; }
        for(int i = 0; i < n; ++i) {
            char const c = s[i];
            if(not seen.count(c)) { 
				while(not ans.empty() and c < ans.back() and i < g[ans.back()-'a']) {
					seen.erase(ans.back()); ans.pop_back();
				}
				ans.push_back(c);
				seen.insert(c);
			}
        }
        return ans;
    }
};
