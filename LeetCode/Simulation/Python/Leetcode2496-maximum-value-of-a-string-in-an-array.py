class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        ans = 0
        def check(s):
            for c in s:
                if c < '0' or c > '9': 
                    return True
            return False
        for s in strs:
            if check(s):
                ans = max(ans, len(s))
            else:
                ans = max(ans, int(s))
        return ans