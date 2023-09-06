# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        def size(head : Optional[ListNode]) -> int:
            length = 0

            while head:
                length += 1
                head = head.next
            
            return length
        
        length = size(head)
        parts, longer_ones = length // k, length % k
        ans = [parts + 1] * longer_ones + [parts] * (k - longer_ones)
        
        prev, curr = None, head
        for index, num in enumerate(ans):
            if prev:
                prev.next = None
            ans[index] = curr
            for i in range(num):
                prev, curr = curr, curr.next
        
        return ans