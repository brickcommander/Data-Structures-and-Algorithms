# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def SUM(self, root) -> int:
        if root == None: return 0
        return root.val + self.SUM(root.left) + self.SUM(root.right)
    
    def convertBST_Helper(self, root):
        if root == None: return
        self.convertBST_Helper(root.left)
        temp = root.val
        root.val = self.sum
        self.sum -= temp
        self.convertBST_Helper(root.right)
    
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.sum = self.SUM(root)
        self.convertBST_Helper(root)
        return root
        
        