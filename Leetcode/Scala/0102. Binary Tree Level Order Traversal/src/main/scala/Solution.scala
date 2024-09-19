



case class TreeNode(val x: Int = 0, val left: TreeNode = null, val right: TreeNode = null)

object Solution {
    def getNodes(node: TreeNode): List[TreeNode] = {
        if (node.left == null && node.right == null) {
            List()
        } else if (node.left != null && node.right == null) {
            List(node.left)
        } else if (node.left == null && node.right != null) {
            List(node.right)
        } else { List(node.left, node.right) }
    }

    def lrx(roots: List[TreeNode], res: List[List[Int]]): List[List[Int]] = {
        if (!roots.isEmpty) {
            lrx(roots.map(getNodes).flatten, roots.map(e => e.value) :: res)
        } else { res.reverse }
    }

    def levelOrder(root: TreeNode): List[List[Int]] = {
        if (root == null) List() else lrx(List(root), List())
    }
}
