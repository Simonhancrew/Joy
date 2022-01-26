from typing import List
class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        nums = list(map(int,','.join(nums).split(',')))
        nums.sort()
        return str(nums[-k])