#Finding path sum in a binary tree
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root is None:
            return False
        sum -= root.val
        if root.left is None and root.right is None and sum==0:
            return True
        return  self.hasPathSum(root.left,sum) or self.hasPathSum(root.right,sum)
