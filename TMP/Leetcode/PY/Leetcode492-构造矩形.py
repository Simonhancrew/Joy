from typing import List
from math import sqrt
class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        l,w = 0,0
        for i in range(1,int(sqrt(area) + 1)):
            if area % i != 0: continue
            j = area // i
            if l * w == 0 or l - w > j - i:
                l,w = j,i
        return [l,w]