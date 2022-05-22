# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getRightMostNode(self, root: TreeNode, curr : TreeNode) -> TreeNode:
        while root.right != None and root.right != curr:
            root = root.right
        return root;
    
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        curr = root
        while curr != None:
            if curr.left == None:
                ans.append(curr.val)
                curr = curr.right
            else:
                rightMostNode = self.getRightMostNode(curr.left, curr)
                if rightMostNode.right == None: # creating the thread
                    rightMostNode.right = curr
                    curr = curr.left
                else: # breaking the thread
                    ans.append(curr.val)
                    curr = curr.right
                    rightMostNode.right = None
        
        return ans