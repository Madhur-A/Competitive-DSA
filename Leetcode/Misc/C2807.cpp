



class Solution {
public:
    void insert(ListNode* root) {
        if(root and root->next) {
            ListNode* returning_node = root->next;
            root->next =
                new ListNode(std::gcd(root->val, returning_node->val), returning_node);
            return insert(returning_node);
        }
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        insert(head);
        return head;
    }
};
