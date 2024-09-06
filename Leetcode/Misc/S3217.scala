/**
 * Definition for singly-linked list.
 * class ListNode(_x: Int = 0, _next: ListNode = null) {
 *   var next: ListNode = _next
 *   var x: Int = _x
 * }
 */


object Solution {
    def modifiedList(nums: Array[Int], head: ListNode): ListNode = {
        val seenSet = nums.toSet
        def rx(sinker: ListNode): ListNode = {
            if (sinker != null) {
                if (seenSet.contains(sinker.x)) {
                    return rx(sinker.next)
                } else {
                    sinker.next = rx(sinker.next)
                }
            }
            return sinker
        }
        return rx(head)
    }
}

