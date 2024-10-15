



object Solution {
    def getXORSum(nums1: Array[Int], nums2: Array[Int]): Int = nums1.reduce(_ ^ _) & nums2.reduce(_ ^ _)
}
