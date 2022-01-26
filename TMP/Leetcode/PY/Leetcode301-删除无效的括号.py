from typing import List
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        l,r = 0,0
        for ch in s:
            if ch == '(': l += 1
            elif ch == ')':
                if l > 0: l -= 1
                else: r += 1
        st = set()
        cur = ''
        def dfs(idx,cur,cnt,l,r):
            if l + r > len(s) - idx: return
            if idx == len(s):
                if cnt == 0: st.add(cur)
                return
            if s[idx]=='(':
                dfs(idx+1,cur + '(',cnt + 1,l,r)
                if l > 0: dfs(idx + 1,cur,cnt,l - 1,r)
            elif s[idx] == ')':
                if cnt > 0: dfs(idx + 1,cur + ')',cnt - 1,l,r)
                if r > 0: dfs(idx + 1,cur,cnt,l,r - 1)
            else:
                dfs(idx + 1,cur + s[idx],cnt,l,r)
        dfs(0,cur,0,l,r)
        res = []
        for c in st:
            res.append(c)
        return res