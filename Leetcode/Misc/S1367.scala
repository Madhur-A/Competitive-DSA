



object Solution {
    def isSubPath(head: ListNode, root: TreeNode): Boolean = {
        def rx(h: ListNode, r: TreeNode): Boolean = {
            if (h != null && r != null) {
                if (h.x == r.value) (rx(h.next, r.left) || rx(h.next, r.right)) else false
            } else { h != null }
        }
        def dx(h: ListNode, r: TreeNode): Boolean = {
            if (h != null && r != null) {
                if (rx(h, r)) true else (dx(h, r.left) || dx(h, r.left))
            } else { h != null }
        }
        dx(head, root)
    }
}
