



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


// this one is fully functional but it exceeds the memory limit of the problem specification
object Solution {
    def spiralMatrix(r: Int, c: Int, head: ListNode): Array[Array[Int]] = {
        val initial = List.fill(r, c)(-1)
        val dirs = List((0,1),(1,0),(0,-1),(-1,0))

        val isValid: (Int, Int, List[List[Int]]) => Boolean = (i, j, res) => ((0 <= i) && (0 <= j) && (i < r) && (j < c) && res(i)(j) == -1)

        def modify(i: Int, j: Int, updatedValue: Int, res: List[List[Int]]): List[List[Int]] = {
            val row = res.take(i + 1).last
            val (front, back) = row.splitAt(j + 1)
            res.take(i + 1).dropRight(1) ++ List(front.dropRight(1) ++ List(updatedValue) ++ back) ++ res.drop(i + 1)
        }

        def rx(i: Int, j: Int, currDir: Int = 0, root: ListNode = head, res: List[List[Int]] = initial): List[List[Int]] = {
            if (root == null) { res } else {
                val newRes = modify(i, j, root.x, res)
                val (h, k) = (dirs(currDir)(0) + i, dirs(currDir)(1) + j)
                if (isValid(h, k, newRes)) { rx(h, k, currDir, root.next, newRes) } else {
                    val newDir = (currDir + 1) % 4
                    rx(dirs(newDir)(0) + i, dirs(newDir)(1) + j, newDir, root.next, newRes)
                }
            }
        }
        
        rx(0, 0).map(_.toArray).toArray
    }    
}
