



// Q: which one is the most ugly?


object Solution {
    def nextGreaterElement(nums1: Array[Int], nums2: Array[Int]): Array[Int] = {
        nums1.map(
            nums2.foldLeft((Map.empty[Int, Int], List.empty[Int])) { case ((seen, stack), num) =>
                (stack.foldLeft(seen) { case (seeing, top) =>
                    if (top < num) { seeing + (top -> num) } else { seeing }
                    }, 
                 num :: stack.dropWhile(_ < num))
            }.head.withDefaultValue(-1)
        )
    }
}



object Solution {
    def nextGreaterElement(nums1: Array[Int], nums2: Array[Int]): Array[Int] = {
        nums1.foldLeft((Array.fill(nums1.length)(-1), 0)) { case ((res, index), num) =>
            res.update(index, 
                nums2.slice(nums2.indexOf(num), 
                            nums2.length).foldLeft((-1, num)) { case ((bigger, thanThis), number) =>
                    if (number <= thanThis) {
                        (bigger, thanThis)
                    } else { (number, Int.MaxValue) }
                }.head)
            (res, index + 1)
        }.head
    }
}

