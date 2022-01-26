from typing import List
class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        res = ''
        dictionary.sort()
        for x in dictionary:
            i,j = 0,0
            while i < len(s) and j < len(x):
                if s[i] == x[j]:
                    i += 1
                    j += 1
                else:
                    i += 1
            if j == len(x) and j > len(res):
                res = x
        return res