



object Solution {
    def deleteDuplicates(head: ListNode): ListNode = {
        def matcher(node: ListNode, prev: Int): ListNode = {
            node match {
                case null => null
                case n if n != null && n.next == null =>
                    if (n.x != prev) n else null
                case n if n != null && n.next != null =>
                    if (n.x != n.next.x && n.x != prev)
                        ListNode(n.x, matcher(n.next, n.x))
                    else
                        matcher(n.next, n.x)
            }
        }
        matcher(head, 101)
    }
}
