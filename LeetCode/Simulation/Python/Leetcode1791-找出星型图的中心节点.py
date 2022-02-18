class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        st = [0] * (n + 1)
        for e in edges:
            st[e[0]] += 1
            st[e[1]] += 1
        for i in range(1,n + 1):
            if st[i] == n - 1: return i
        return -1