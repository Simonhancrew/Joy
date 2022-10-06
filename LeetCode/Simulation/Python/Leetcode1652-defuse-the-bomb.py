class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        ans = [0] * n
        if k == 0: return ans
        for i in range(n):
            if k > 0:
                acc = 0
                for j in range(i + 1, i + 1 + k):
                    acc += code[j % n]
                ans[i] = acc
            else:
                acc = 0
                for j in range(i - 1, i + k - 1, -1):
                    acc += code[(j + n) % n]
                ans[i] = acc
        return ans
