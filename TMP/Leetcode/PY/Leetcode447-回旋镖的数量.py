from typing import List
from collections import defaultdict


class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        res = 0
        for p in points:
            mp = defaultdict(int)
            for q in points:
                dis = (p[0] - q[0]) ** 2 + (p[1] - q[1]) ** 2
                mp[dis] += 1
            for _,v in mp.items():
                res += (v - 1) * v
        return res