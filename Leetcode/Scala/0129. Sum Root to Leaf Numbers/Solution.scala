



object Solution {
    def rx(node: TreeNode, curr: List[Int] = List[Int]()): Int = node match {
        case null => 0
        case    _ => (node.left == null && node.right == null) match {
            case  true => (node.value :: curr).mkString.reverse.toInt
            case false => rx(node.left, node.value :: curr) + rx(node.right, node.value :: curr)
        }
    }

    def sumNumbers(root: TreeNode): Int = rx(root)
}
