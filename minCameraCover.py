class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        def dfs(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            res = dfs(node.left)+dfs(node.right)
            curr = min(node.left.val if node.left else float('inf'), node.right.val if node.right else float('inf'))
            if curr == 0:
                node.val = 1
                res += 1
            elif curr == 1:
                node.val = 2
            return res
        return dfs(root)+(root.val == 0)
