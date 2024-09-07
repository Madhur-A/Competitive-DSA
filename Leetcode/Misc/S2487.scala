



object Solution {
    def removeNodes(root: ListNode): ListNode = {
        def rx(sinker: ListNode, seen: Int = Int.MinValue): (ListNode, Int) = {
            if (sinker != null) {
                val in_transit = rx(sinker.next, seen)
                if (in_transit.last <= sinker.x) {
                    sinker.next = in_transit.head
                    (sinker, sinker.x)
                } else { in_transit }                
            } else { (null, seen) }
        }
        rx(root).head
    }
}

