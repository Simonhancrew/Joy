class Solution:
    def sequenceReconstruction(self, nums: List[int],
                               sequences: List[List[int]]) -> bool:
        n = len(nums)
        g, din = [[] for _ in range(n + 1)], [0] * (n + 1)
        for se in sequences:
            for x, y in pairwise(se):
                g[x].append(y)
                din[y] += 1
        q = deque()
        for i in range(1, n + 1):
            if din[i] == 0:
                q.append(i)

        while q:
            if (len(q)) > 1: return False
            x = q.popleft()
            for y in g[x]:
                din[y] -= 1
                if din[y] == 0:
                    q.append(y)
        return True
