# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def helper(self, root, app):
        if root == None: return app
        app = self.helper(root.right, app)
        root.right = app
        temp = root.left;
        root.left = None
        app = root
        return self.helper(temp, app)
    
    def increasingBST(self, root: TreeNode) -> TreeNode:
        return self.helper(root, None)