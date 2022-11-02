class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        mx,my = -1, -1
        mx = max(t[0] for t in towers)
        my = max(t[1] for t in towers)
        tx = ty = qua = 0
        for x in range(mx + 1):
            for y in range(my + 1):
                q = 0
                for t in towers:
                    d = (x - t[0]) ** 2 + (y - t[1]) ** 2
                    if d <= radius ** 2:
                        q += t[2] // (1 + d ** 0.5)
                if q > qua:
                    tx, ty, qua = x, y, q
        return [tx, ty]
