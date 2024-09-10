



object Solution {
    val gcd: (Int, Int) => Int = (a, b) => if (b == 0) a else { gcd(b, a % b) }

    def insertGreatestCommonDivisors(head: ListNode): ListNode = {
        if (head != null && head.next != null) {
            new ListNode(head.x , new ListNode(gcd(head.x, head.next.x), insertGreatestCommonDivisors(head.next)))
        } else { head }
    }
}
