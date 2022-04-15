# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        if root == None: return ""
        st = str()
        
        st = str(root.val)
        if root.left or root.right:
            st = st + "(" + self.tree2str(root.left) + ")"
            if root.right:
                st = st + "(" + self.tree2str(root.right) + ")"
        
        return st
        