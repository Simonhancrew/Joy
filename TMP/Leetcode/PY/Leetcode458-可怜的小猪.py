class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        k = minutesToTest // minutesToDie
        return math.ceil(math.log(buckets) / math.log(k + 1))