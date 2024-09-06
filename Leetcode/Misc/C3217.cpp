/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    std::unordered_set<int> seen;
public:
    ListNode* rx(ListNode* r) {
        if(r) {
            if(seen.count(r->val)) {
                return rx(r->next);
            } else {
                r->next = rx(r->next);
            }
        }
        return r;
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        seen.insert(nums.begin(), nums.end());

        return rx(head);
    }
};
