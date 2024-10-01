



object Solution {
    def check(freqs: Array[Int], k: Int): Boolean = freqs.length match {
        case 0 => true
        case _ => {
            if (freqs.head + freqs.last == k) { 
                check(freqs.tail.dropRight(1), k) 
            } else { false }    
        }
    }    
    
    def canArrange(nums: Array[Int], k: Int): Boolean = {
        val rems = nums.map(e => ((e % k) + k) % k)
        if ((rems.count(e => e == 0) & 1) == 0) {
            check(rems.filter(e => e != 0).sorted, k)
        } else { false }
    }
}
