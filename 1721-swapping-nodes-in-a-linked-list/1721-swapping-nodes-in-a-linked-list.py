# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        a = b = head
        kth = ListNode()
        
        for i in range(1, k):
            a = a.next
            
        kth = a
        
        while a.next != None:
            a = a.next
            b = b.next
        
        kth.val, b.val = b.val, kth.val
        
        return head;
        