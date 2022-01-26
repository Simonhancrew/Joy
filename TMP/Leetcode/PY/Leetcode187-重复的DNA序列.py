from typing import List
from collections import defaultdict

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        n = len(s)
        res = []
        mp = defaultdict(int)
        if n < 10:
            return res
        for i in range(n - 9):
            cur = s[i:i + 10]
            mp[cur] += 1
            if mp[cur] == 2:
                res.append(cur)
        return res