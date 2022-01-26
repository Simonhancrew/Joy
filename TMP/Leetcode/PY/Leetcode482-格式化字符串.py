class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        ans = []
        cnt = 0
        for i in range(len(s) - 1,-1,-1):
            if s[i] == '-': continue
            if cnt == k:
                ans.append('-')
                cnt = 0
            ans.append(s[i])
            cnt += 1
        ans.reverse()
        return ''.join(ans).upper()