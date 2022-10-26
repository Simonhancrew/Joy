class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        s = [0] * (n + 1)
        for i in range(1, n + 1): s[i] = s[i - 1] + nums[i - 1]
        res = int(1e8)
        q = deque()
        q.append(0)
        for i in range(1, n + 1):
            while q and s[q[0]] + k <= s[i]:
                res = min(res, i - q[0])
                q.popleft()
            while q and s[q[-1]] >= s[i]:
                q.pop()
            q.append(i)
        if res == int(1e8): return -1
        return res 