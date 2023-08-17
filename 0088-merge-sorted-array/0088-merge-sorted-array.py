class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        a, b, idx = m-1, n-1, m+n-1

        while a >= 0 and b >= 0:
            if nums1[a] > nums2[b]:
                nums1[idx] = nums1[a]
                idx -= 1
                a -= 1
            else:
                nums1[idx] = nums2[b]
                idx -= 1
                b -= 1

        while b >= 0:
            nums1[idx] = nums2[b]
            idx -= 1
            b -= 1