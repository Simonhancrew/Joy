class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        st, ans = set(), 0
        for x in nums: st.add(x)
        for x in nums:
            if x + diff in st and x + 2 * diff in st:
                ans += 1
        return ans
