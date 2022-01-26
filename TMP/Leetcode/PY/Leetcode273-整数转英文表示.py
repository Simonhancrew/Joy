num19 = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
    "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
    "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
    "Nineteen"]
num20 = ["Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
    "Eighty", "Ninety"]
num1000 = [ "Billion ", "Million ", "Thousand ",""]

class Solution:
    def numberToWords(self, num: int) -> str:      
        if num == 0:
            return num19[0]
        def get(x):
            res = ''
            if x >= 100:
                res += num19[x // 100] + ' Hundred '
                x %= 100
            if x >= 20:
                res += num20[x // 10 - 2] + ' '
                x %= 10
            if x != 0:
                res += num19[x] + ' '
            return res
        i,j = int(1e9),0
        res = ''
        while i >= 1:
            if num >= i:
                res += get(num // i) + num1000[j]
                num %= i
            i //= 1000
            j += 1
        return res[:-1]