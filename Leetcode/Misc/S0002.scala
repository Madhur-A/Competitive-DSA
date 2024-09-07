



object Solution {
    def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {
        val nextVal = (node: ListNode) => if (node == null) 0 else node.x
        val nextNode = (node: ListNode) => if (node == null) null else node.next

        def addNodes(l1: ListNode, l2: ListNode, carry: Int): ListNode = {
            if (l1 == null && l2 == null && carry == 0) { null
            } else {
                val total = nextVal(l1) + nextVal(l2) + carry
                val node = new ListNode(total % 10)
                node.next = addNodes(nextNode(l1), nextNode(l2), total / 10); node
            }
        }
        addNodes(l1, l2, 0)
    }    
}

