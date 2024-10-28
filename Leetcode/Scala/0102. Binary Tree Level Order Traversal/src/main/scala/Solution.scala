



object Solution {
    def getNodes(node: TreeNode): List[TreeNode] = (node.left, node.right) match {
        case (null, null) => List()
        case (_,    null) => List(node.left)
        case (null,    _) => List(node.right)
        case           _  => List(node.left, node.right)
    }

    def lrx(roots: List[TreeNode], res: List[List[Int]]): List[List[Int]] = roots.nonEmpty match {
        case  true => lrx(roots.map(getNodes).flatten, roots.map(e => e.value) :: res)
        case false => res.reverse
    }

    def levelOrder(root: TreeNode): List[List[Int]] = root match {
        case  null => List()
        case     _ => lrx(List(root), List())
    }
}
