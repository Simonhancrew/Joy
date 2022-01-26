class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        st,n = set(),len(nums)
        for i in range(n):
            if i > k: st.remove(nums[i - k - 1])
            if nums[i] in st: return True
            st.add(nums[i])
        return False