



object Solution {
    def spiralMatrix(r: Int, c: Int, head: ListNode): Array[Array[Int]] = {
        val res = Array.fill(r, c)(-1)
        val dirs = Array((0,1),(1,0),(0,-1),(-1,0))
        val isValid: (Int, Int) => Boolean = (i, j) => ((0 <= i) && (0 <= j) && (i < r) && (j < c) && res(i)(j) == -1)
        
        def rx(i: Int, j: Int, currDir: Int = 0, root: ListNode = head): Array[Array[Int]] = {
            if (root == null) { res } else {
                res(i)(j) = root.x
                val (h, k) = (dirs(currDir).head + i, dirs(currDir).last + j)
                if (isValid(h, k)) { rx(h, k, currDir, root.next) } else {
                    val newDir = (currDir + 1) % 4
                    rx(dirs(newDir)(0) + i, dirs(newDir)(1) + j, newDir, root.next)
                }
            }
        }
        
        rx(0, 0)
    }    
}
