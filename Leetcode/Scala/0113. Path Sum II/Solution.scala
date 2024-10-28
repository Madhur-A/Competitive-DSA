



object Solution {
    def rx(node: TreeNode, target: Int, currPath: List[Int]): List[List[Int]] = {
        val isLeaf = (node != null && node.left == null && node.right == null)
        node == null match {
            case  true => List()
            case false => (isLeaf && currPath.sum + node.value == target) match {
                case  true => List((node.value :: currPath).reverse)
                case false => rx(node.left, target, node.value :: currPath) ::: rx(node.right, target, node.value :: currPath)
            }
        }
    }

    def pathSum(root: TreeNode, targetSum: Int): List[List[Int]] = {
        rx(root, targetSum, List[Int]())
    }
}
