from typing import List
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        i = 0
        while i < len(words):
            j = i + 1
            length = len(words[i])
            while j < len(words) and length + 1 + len(words[j]) <= maxWidth:
                length += 1 + len(words[j]) 
                j += 1
            
            line = ''
            if j == len(words) or j == i + 1:
                line += words[i]
                for k in range(i + 1,j):
                    line += ' ' + words[k] 
                while len(line) < maxWidth:
                    line += ' '
            else:
                cnt = j - i - 1
                r = maxWidth - length + cnt
                line += words[i]
                k = 0
                while k < r % cnt:
                    line += ' ' * (r // cnt + 1) + words[i + k + 1]
                    k += 1
                while k < cnt:
                    line += ' ' * (r // cnt) + words[i + k + 1]
                    k += 1
            res.append(line)
            i = j 
        return res