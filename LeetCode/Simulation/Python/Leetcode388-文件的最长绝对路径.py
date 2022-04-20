class Solution:
    def lengthLongestPath(self, input: str) -> int:
        res = 0
        i,tot,stk,res = 0,0,[],0
        while i < len(input):
            k = 0
            while i < len(input) and input[i] == '\t':
                i += 1
                k += 1
            while k < len(stk):
                tot -= stk.pop()
            j = i
            while j < len(input) and input[j] != '\n':
                j += 1
            length = j - i
            stk.append(length)
            tot += length      
            if '.' in input[i:j]:
                res = max(res,tot + len(stk) - 1)
            i = j + 1
        return res