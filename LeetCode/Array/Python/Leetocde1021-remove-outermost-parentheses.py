class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans,n,i = [],len(s),0
        while i < n:
            j,cnt = i + 1,1
            while j < n and cnt != 0:
                if s[j] == '(': cnt += 1
                else: cnt -= 1
                j += 1
            ans.append(s[i + 1:j - 1])
            i = j
        return ''.join(ans)