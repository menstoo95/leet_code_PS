# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        val, ptr, cnt, curr = [], [], 0, head

        while curr:
            cnt += 1
            if cnt >= left and cnt <= right:
                val.append(curr.val)
                ptr.append(curr)
            curr = curr.next
        
        for p in ptr:
            p.val = val.pop(-1)
        
        return head
        

        