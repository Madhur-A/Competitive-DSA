



object Solution {
    def reverseList(head: ListNode, rest: ListNode = null): ListNode = {
        if (head == null) { rest } else {
            reverseList(head.next, ListNode(head.x, rest))
        }
    }
}

