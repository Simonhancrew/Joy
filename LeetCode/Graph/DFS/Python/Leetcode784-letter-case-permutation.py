class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        n, ans = len(s), []
        s = list(s)
        def dfs(i):
            nonlocal n
            if i == n: 
                ans.append(''.join(s))
                return 
            dfs(i + 1)
            if not s[i].isdigit():
                s[i] = s[i].swapcase()
                dfs(i + 1)
                s[i] = s[i].swapcase()
        dfs(0)
        return ans
