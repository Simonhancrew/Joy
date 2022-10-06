class Solution:
    def longestWord(self, words: List[str]) -> str:
        N = int(3e4 + 10)
        son = [[0] * 26 for _ in range(N)]
        idx, id = 0, [-1] * N

        def insert(s, idc):
            nonlocal idx
            p = 0
            for i in range(len(s)):
                t = ord(s[i]) - ord('a')
                if son[p][t] == 0:
                    son[p][t] = idx + 1
                    idx += 1
                p = son[p][t]
            # print(son[0])
            id[p] = idc

        def dfs(p, length):
            res = [length, id[p]]
            for i in range(26):
                j = son[p][i]
                if j != 0 and id[j] != -1:
                    t = dfs(j, length + 1)
                    if t[0] > res[0]:
                        res = t
            return res

        for i in range(len(words)):
            insert(words[i], i)
        t = dfs(0, 0)
        if t[1] != -1:
            return words[t[1]]
        return ''
