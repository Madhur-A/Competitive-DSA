



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
	std::unordered_map<int, int> g; // node -> height
	std::vector<int> otherwise;
public:
	int hx(TreeNode* node) {
        return node ? g[node->val] = (1 + std::max(hx(node->left), hx(node->right))) : 0;
	}

	void rx(TreeNode* node, int const &curr = 0, int const &aliter = 0) {
		if(node) {
			otherwise[node->val] = aliter;
			rx(node->left,  curr + 1, std::max(curr + (node->right ? g[node->right->val] : 0), aliter));
			rx(node->right, curr + 1, std::max(curr + (node->left  ? g[node->left->val] :  0), aliter));
		}
	}

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
		hx(root);
		otherwise.resize(g.size() + 1);
		rx(root);

		std::vector<int> res;
		for(int const &query: queries) {
			res.emplace_back(otherwise[query]);
		}

		return res;
    }
};
