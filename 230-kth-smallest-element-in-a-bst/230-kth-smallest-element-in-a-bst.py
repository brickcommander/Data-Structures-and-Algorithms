# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root: Optional[TreeNode]):
        if root == None: return -1
        x = self.helper(root.left)
        if x != -1: return x
        if self.k == 1:
            return root.val
        self.k -= 1
        x = self.helper(root.right)
        if x != -1: return x
        return -1
        
        
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.k = k
        return self.helper(root)