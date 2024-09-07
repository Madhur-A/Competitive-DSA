



class Solution {
public:
	bool rx(ListNode* h, TreeNode* r) {
		if(h and r) {
			return (h->val == r->val) ? rx(h->next, r->left) or rx(h->next, r->right) : false;
		}
		return h == nullptr;
	}

	bool dfs(ListNode* h, TreeNode* r) {
		if(h and r) {
            return rx(h, r) ? true : dfs(h, r->left) or dfs(h, r->right);
		}
        return h == nullptr;
	}

    bool isSubPath(ListNode* head, TreeNode* root) {
		return dfs(head, root);
    }
};
