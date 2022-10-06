class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        def gcd(a, b):
            return gcd(b, a % b) if b != 0 else a

        ans = []
        for i in range(2, n + 1):
            for j in range(1, i):
                if gcd(j, i) == 1:
                    ans.append(str(j) + '/' + str(i))
        return ans
