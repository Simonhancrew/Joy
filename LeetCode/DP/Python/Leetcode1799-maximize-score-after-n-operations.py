class Solution:
    def maxScore(self, nums: List[int]) -> int:
        n = len(nums)
        f = [0] * (1 << n)
        for i in range(1 << n):
            cnt = 0
            for j in range(n):
                if (i >> j & 1) == 0:
                    cnt += 1
            if cnt & 1 == 1: continue
            cnt = cnt // 2 + 1
            for j in range(n):
                if i >> j & 1 == 1:
                    for k in range(j + 1, n):
                        if i >> k & 1 == 1:
                            f[i] = max(f[i], f[i - (1 << j) - (1 << k)] + cnt * gcd(nums[j], nums[k]))
        return f[(1 << n) - 1]