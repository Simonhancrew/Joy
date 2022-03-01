class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        res,tot = [],len(s)
        for i in range(numRows):
            if i == 0 or i == numRows - 1:
                for j in range(i,tot,2 * numRows - 2):
                    res.append(s[j])
            else:
                j,k = i,2 * numRows - 2 - i
                while j < tot or k < tot:
                    if j < tot: res.append(s[j])
                    if k < tot: res.append(s[k])
                    j,k = j + 2 * numRows - 2,k + 2 * numRows - 2
        return ''.join(res) 