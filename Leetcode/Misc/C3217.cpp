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

// no compromise on recursion though, (lol!)

class Solution {
public:
    std::unordered_set<int> seen;
public:
    ListNode* find(ListNode* r) {
        return (r and seen.count(r->val)) ? find(r->next) : r;
    }

    ListNode* rx(ListNode* r) {
        if(r) {
            r->next = rx(r->next);
            if(r and seen.count(r->val)) {
                return r->next;
            }
        }
        return r;
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        seen.insert(nums.begin(), nums.end());
        ListNode* contingent = new ListNode(INT_MAX);
        contingent->next = find(head);
        rx(contingent->next);
        return contingent->next;
    }
};
