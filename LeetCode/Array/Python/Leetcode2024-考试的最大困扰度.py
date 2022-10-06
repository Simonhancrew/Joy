class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        cnt0, cnt1, n, l, ans = 0, 0, len(answerKey), 0, 1
        for r in range(n):
            if answerKey[r] == 'T': cnt1 += 1
            else: cnt0 += 1

            while l < r and min(cnt0, cnt1) > k:
                if answerKey[l] == 'T': cnt1 -= 1
                else: cnt0 -= 1
                l += 1

            ans = max(ans, r - l + 1)
        return ans
