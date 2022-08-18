class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        cnt,freq = defaultdict(int),defaultdict(int)
        n,ans,max_f = len(nums),0,0
        for i in range(n):
            num = nums[i]
            if cnt[num] > 0:
                freq[cnt[num]] -= 1
            cnt[num] += 1
            freq[cnt[num]] += 1
            max_f = max(max_f,cnt[num])
            if max_f == 1 or max_f * freq[max_f] == i or (max_f - 1) * (freq[max_f - 1] + 1) == i: 
                ans = i + 1
        return ans