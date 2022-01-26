class Solution:

    def __init__(self, nums: List[int]):
        self.memo = nums

    def reset(self) -> List[int]:
        return self.memo

    def shuffle(self) -> List[int]:
        cp = copy.deepcopy(self.memo)
        shuffle(cp)
        return cp
