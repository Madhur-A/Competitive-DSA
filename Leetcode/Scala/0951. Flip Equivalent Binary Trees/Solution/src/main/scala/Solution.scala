



object Solution {
    def flipEquiv(r: TreeNode, s: TreeNode): Boolean = (r == null || s == null) match {
        case false => (r.value == s.value) match {
            case false => false
            case  true => (flipEquiv(r.left, s.right) && flipEquiv(r.right, s.left)) || (flipEquiv(r.left, s.left) && flipEquiv(r.right, s.right))
        }
        case  true => (r == null && s == null)
    }
}
