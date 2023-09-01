class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        res = int(1e9)
        st = set()
        d = [0] * (n + 1)
        for x in edges:
            a, b = x[0], x[1]
            if a > b: 
                a, b = b, a
            d[a] += 1
            d[b] += 1
            st.add((a, b))

        for i in range(1, n + 1):
            for j in range(i + 1, n + 1):
                if (i, j) in st:
                    for k in range(j + 1, n + 1):
                        if (i, k) in st and (j, k) in st:
                            res = min(res, d[i] + d[j] + d[k] - 6)

        if res == int(1e9):
            return -1
        return res