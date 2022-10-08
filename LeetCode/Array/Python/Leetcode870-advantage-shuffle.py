class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums1)
        nums1.sort()
        idx, ans = [i for i in range(n)], [0] * n
        idx.sort(key = lambda x : nums2[x])
        l,r = 0, n - 1
        for i in range(n):
            if nums1[i] > nums2[idx[l]]:
                ans[idx[l]] = nums1[i]
                l += 1
            else:
                ans[idx[r]] = nums1[i]
                r -= 1
        return ans
