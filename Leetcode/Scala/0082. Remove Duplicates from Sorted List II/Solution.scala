



object Solution {
    def deleteDuplicates(head: ListNode): ListNode = {
        def matcher(node: ListNode, prev: Int): ListNode = node match {
            case null => null
            case n if n != null && n.next == null => if (n.x != prev) n else null
            case n if n != null && n.next != null => (n.x != n.next.x && n.x != prev) match {
                case  true => ListNode(n.x, matcher(n.next, n.x))
                case false => matcher(n.next, n.x)
            }
        }
        matcher(head, 101)
    }
}
