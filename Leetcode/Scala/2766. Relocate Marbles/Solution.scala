



object Solution {
    def relocateMarbles(nums: Array[Int], moveFrom: Array[Int], moveTo: Array[Int]): List[Int] = {
        moveFrom.foldLeft((nums.toSet, 0)) { case ((numsSet, index), _) =>
            (numsSet.-(moveFrom(index)).+(moveTo(index)), index + 1)
        }.head.toList.sorted
    }
}
