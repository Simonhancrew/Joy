class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        help,n = [],len(score)
        for i in range(n):
            help.append([score[i],i])
        help.sort(key = lambda help : help[0])
        cnt = 1
        res = ['0'] * n
        for i in range(n - 1,-1,-1):
            if cnt == 1: res[help[i][1]] = "Gold Medal"
            elif cnt == 2: res[help[i][1]] = "Silver Medal"
            elif cnt == 3: res[help[i][1]] = "Bronze Medal"
            else: res[help[i][1]] = str(cnt)
            cnt += 1
        return res