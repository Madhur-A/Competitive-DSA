



object Solution {
    def reverseList(root: ListNode): ListNode = {
        if (root != null) {
            if (root.next == null) { root } else {
                val returnOfTheRoot = reverseList(root.next)
                root.next.next = root
                root.next = null
                returnOfTheRoot
            }
        } else { null }
    }
}
