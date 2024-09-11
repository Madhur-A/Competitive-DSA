



// using indexing

object Solution {
    def maxStrength(nums: Array[Int]): Long = {
        def rx(curr: Long, index: Int): Long = {
            if (index == nums.length) { curr
            } else {
                if (nums(index) != 0) {
                    val pick = rx(curr * nums(index), index + 1)
                    val skip = rx(nums(index), index + 1)
                    val prev = rx(curr, index + 1)
                    math.max(prev, math.max(pick, skip))
                } else { rx(curr, index + 1) }
            }
        }
        
        if (nums.length == 1) nums(0) else rx(0L, 0)
    }
}

// without using indexing (see the Erlang solution for a pattern-matching approach),
// the one given below also does it; however, it is not as explicit as in Erlang.

object Solution {
    def maxStrength(nums: Array[Int]): Long = {
        def rx(numbers: List[Int], res: Long): Long = {
            if (numbers.isEmpty) { res
            } else {
                math.max(rx(numbers.tail, numbers.head * res),                    
                    math.max(rx(numbers.tail, numbers.head),rx(numbers.tail, res)))
            }
        }
        if (nums.tail.isEmpty) nums.head else rx(nums.toList, 0L)
    }
}
