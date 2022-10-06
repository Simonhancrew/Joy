from functools import cache


class Solution:
    def canPartitionKSubsets(self, nums, k):
        acc, n = sum(nums), len(nums)
        if acc % k != 0: return False
        ave = acc // k
        nums.sort(reverse=True)
        st = 0

        @cache
        def dfs(start, cur, cnt, st):
            if cnt == 1: return True
            if cur > ave: return False
            if cur == ave: return dfs(0, 0, cnt - 1, st)
            for i in range(start, n):
                if (st >> i) & 1 == 1: continue
                if cur + nums[i] <= ave:
                    st ^= (1 << i)
                    if dfs(start + 1, cur + nums[i], cnt, st):
                        return True
                    st ^= (1 << i)
                if cur == 0: return False
            return False

        return dfs(0, 0, k, st)


if __name__ == "__main__":
    arr = [4, 5, 9, 3, 10, 2, 10, 7, 10, 8, 5, 9, 4, 6, 4, 9]
    k = 5
    s = Solution()
    print(s.canPartitionKSubsets(arr, k))
