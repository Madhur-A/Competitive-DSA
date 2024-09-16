



object Solution {
    def hook(sinker: ListNode): ListNode = {
        if (sinker != null) {
            if (sinker.next != null) {
                ListNode(sinker.x, sinker.next.next)
            } else { null }
        } else { null }
    }

    def slowTracker(slow: ListNode, fast: ListNode): ListNode = {
        if (fast != null) {
            ListNode(slow.x, next = slowTracker(slow.next, fast.next))
        } else { hook(slow) }
    }

    def fastTracker(trueTrack: ListNode, track: ListNode, fastCount: Int, fromTheEnd: Int): ListNode = {
        if (fastCount < fromTheEnd) {
            fastTracker(trueTrack, track.next, fastCount + 1, fromTheEnd)
        } else {
            if (track != null) {
                slowTracker(trueTrack, track.next)
            } else {
                trueTrack.next
            }
        }
    }

    def removeNthFromEnd(head: ListNode, n: Int): ListNode = {
        fastTracker(head, head, 0, n)
    }
}
