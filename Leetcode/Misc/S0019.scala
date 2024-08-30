/**
 * Definition for singly-linked list.
 * class ListNode(_x: Int = 0, _next: ListNode = null) {
 *   var next: ListNode = _next
 *   var x: Int = _x
 * }
 */


object Solution {
    def removeNthFromEnd(head: ListNode, n: Int): ListNode = {
        var indexFromEnd = 0;
        def rx(tracker: ListNode): ListNode = {
            if (tracker != null) {
                tracker.next = rx(tracker.next)
                indexFromEnd += 1
                if (indexFromEnd == n) {
                    return tracker.next
                }
            }
            return tracker
        }
        rx(head)
    }
}
