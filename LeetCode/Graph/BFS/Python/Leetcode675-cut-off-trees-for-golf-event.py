class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        n, m = len(forest), len(forest[0])
        trees = []
        for i in range(n):
            for j in range(m):
                if forest[i][j] > 1:
                    trees.append([forest[i][j], i, j])
        trees.sort()

        def bfs(st, to):
            if st[1] == to[1] and st[2] == to[2]: return 0
            x, y = st[1], st[2]
            dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]
            q, dist = deque(), [[1000000] * m for _ in range(n)]
            dist[x][y] = 0
            q.append([x, y])
            while q:
                t = q.popleft()
                for i in range(4):
                    nx, ny = t[0] + dx[i], t[1] + dy[i]
                    if nx >= 0 and nx < n and ny >= 0 and ny < m and forest[
                            nx][ny] != 0:
                        if dist[nx][ny] > dist[t[0]][t[1]] + 1:
                            dist[nx][ny] = dist[t[0]][t[1]] + 1
                            if nx == to[1] and ny == to[2]: return dist[nx][ny]
                            q.append([nx, ny])
            return -1

        st, res = [0, 0, 0], 0
        for to in trees:
            t = bfs(st, to)
            if t == -1: return -1
            res += t
            st = to
        return res
