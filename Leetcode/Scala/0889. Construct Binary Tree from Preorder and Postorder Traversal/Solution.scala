/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */

object Solution {
    def constructFromPrePost(preorder: Array[Int], postorder: Array[Int]): TreeNode = {
        if(preorder.nonEmpty && postorder.nonEmpty) {
            val root = new TreeNode(preorder(0))
            if(preorder.length == 1) { return root; }
            val leftRootValue = preorder(1)
            val leftSize = postorder.indexOf(leftRootValue)
            root.left  = constructFromPrePost(preorder.slice(1, leftSize + 2), 
                                              postorder.slice(0, leftSize + 1))
            root.right = constructFromPrePost(
                                        preorder.slice(leftSize + 2, preorder.length), 
                                        postorder.slice(leftSize + 1, postorder.length - 1))
            return root // explicit return
        }
        null
    }
}
