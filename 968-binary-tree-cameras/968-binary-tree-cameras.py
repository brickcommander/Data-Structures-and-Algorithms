# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    '''
        all sub nodes covered (not including itself) -> return 1
        covered using at least one of the child -> return 0
        covered using itself -> return -1
    '''
    def go(self, root: TreeNode): # {camera installed, camera not installed}
        if not root:
            return 0
        l = self.go(root.left)
        r = self.go(root.right)
        
        if l == 1 or r == 1:
            self.camera += 1
            return -1
        if l == -1 or r == -1:
            return 0
        return 1

    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        self.camera = 0
        if self.go(root) == 1:
            self.camera += 1
        return self.camera