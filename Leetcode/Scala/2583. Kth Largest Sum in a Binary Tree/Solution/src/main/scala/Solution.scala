



object Solution {
    def kthLargestLevelSum(root: TreeNode, k: Int): Long = {
        def rx(roots: List[TreeNode], sums: List[Long]): List[Long] = roots.isEmpty match {
            case  true => sums
            case false => {
                rx(
                    roots.foldLeft(List[TreeNode]()) { case (children, root) =>
                        (root != null) match {
                            case  true => root.left :: root.right :: children
                            case false => children
                        }
                    },
                    roots.foldLeft(0L) { case (res, root) =>
                        (root != null) match {
                            case  true => res + root.value
                            case false => res
                        }
                    } :: sums
                )
            }
        }

        val values = rx(List(root), List[Long]()).sorted.reverse.dropRight(1)

        (k <= values.length) match {
            case  true => values(k - 1)
            case false => -1
        }
    }
}
