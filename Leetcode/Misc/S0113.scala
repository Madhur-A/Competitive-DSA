



object Solution {
    def rx(node: TreeNode, target: Int, currPath: List[Int]): List[List[Int]] = {
        val isLeaf = (node != null && node.left == null && node.right == null)
        if (node == null) { List() } else {
            if (isLeaf && currPath.sum + node.value == target) { List(currPath :+ node.value) } else {
                rx(node.left, target, currPath :+ node.value) ++ rx(node.right, target, currPath :+ node.value)
            }
        } 
    }

    def pathSum(root: TreeNode, targetSum: Int): List[List[Int]] = {
        rx(root, targetSum, List[Int]())
    }
}
