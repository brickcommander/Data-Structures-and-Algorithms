# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        queue = []
        answer = []
        if root: queue.append(root)
        
        while queue:
            sz = len(queue)
            level = []
            while sz>0:
                sz -= 1
                f = queue.pop(0)
                level.append(f.val)
                if f.left:
                    queue.append(f.left)
                if f.right:
                    queue.append(f.right)
            answer.append(level)
        
        answer.reverse()
        return answer
                