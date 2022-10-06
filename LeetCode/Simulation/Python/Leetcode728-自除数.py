class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        res = []

        def check(num):
            tmp = num
            while tmp != 0:
                t = tmp % 10
                tmp //= 10
                if t == 0 or num % t != 0: return False
            return True

        for i in range(left, right + 1):
            if check(i): res.append(i)
        return res
