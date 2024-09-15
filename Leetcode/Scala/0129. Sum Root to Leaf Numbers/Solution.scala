



object Solution {
    def rx(node: TreeNode, curr: List[Int] = List[Int]()): Int = {
        if (node == null) { 0 } else {
            if (node.left == null && node.right == null) { (curr :+ node.value).mkString.toInt } else {
                rx(node.left, curr :+ node.value) + rx(node.right, curr :+ node.value)
            }
        }
    }
    
    def sumNumbers(root: TreeNode): Int = rx(root)
}

