"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        
        hs = {}
        cur = head

        while cur:
            hs[cur] = Node(cur.val)
            cur = cur.next
        
        cur = head

        while cur:
            dcopy = hs[cur]
            dcopy.next = hs.get(cur.next)
            dcopy.random = hs.get(cur.random)
            cur = cur.next
        
        return hs[head]
            