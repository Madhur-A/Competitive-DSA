



object Solution {
    def rx(node: TreeNode, curr: List[Int] = List[Int](), res: Int = 0): Int = {
        if (node == null) { 0 } else {
            if (node.left == null && node.right == null) { res + (curr :+ node.value).mkString.toInt } else {
                rx(node.left, curr :+ node.value, res) + rx(node.right, curr :+ node.value, res)
            }
        }
    }
    
    def sumNumbers(root: TreeNode): Int = rx(root)
}

