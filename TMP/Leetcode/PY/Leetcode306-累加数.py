class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        rec = []
        n = len(num)
        def dfs(u,rec):
            cnt = len(rec)
            if u == n: return cnt > 2
            rhs = u + 1 if num[u] == '0' else n
            cur = []
            for i in range(u,rhs):
                cur.insert(0,ord(num[i]) - ord('0'))
                if cnt < 2 or check(rec[cnt - 2],rec[cnt - 1],cur):
                    rec.append(cur)
                    if dfs(i + 1,rec): return True
                    rec.pop()
            return False
        def check(l,r,res):
            carry,i = 0,0
            t = []
            while i < len(r) or i < len(l):
                if i < len(l): carry += l[i]
                if i < len(r): carry += r[i]
                t.append(carry % 10)
                carry //= 10
                i += 1
            if carry != 0: t.append(carry)
            if len(t) != len(res): return False
            for i in range(len(t)):
                if t[i] != res[i]: return False
            return True
        return dfs(0,rec)