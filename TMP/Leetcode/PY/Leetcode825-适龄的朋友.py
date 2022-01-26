class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        n,cnt = len(ages),[0] * 121
        ans = n ** 2
        for age in ages: cnt[age] += 1
        for i in range(1,121):
            for j in range(1,121):
                if j <= 0.5 * i + 7 or j > i:
                    ans -= cnt[i] * cnt[j]
                elif i == j:
                    ans -= cnt[i]
        return ans