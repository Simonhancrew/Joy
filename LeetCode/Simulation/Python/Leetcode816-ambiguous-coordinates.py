class Solution:
    def ambiguousCoordinates(self, s: str) -> List[str]:
        s, res = s[1:len(s) - 1], []
        def get(s):
            ans = []
            if len(s) == 1 or s[0] != '0': ans.append(s)
            for i in range(1, len(s)):
                l, r = s[0:i], s[i:]
                if len(l) > 1 and l[0] == '0': continue
                if r[-1] == '0': continue
                ans.append(l + '.' + r)
            return ans
        for i in range(1,len(s)):
            l, r = get(s[0:i]), get(s[i:])
            for x in l:
                for y in r:
                    res.append('(' + x + ', ' + y + ')')
        return res

