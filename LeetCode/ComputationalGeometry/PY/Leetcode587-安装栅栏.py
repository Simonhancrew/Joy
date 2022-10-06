class Solution:
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        trees.sort()
        n = len(trees)

        def cross(x1, y1, x2, y2):
            return x1 * y2 - x2 * y1

        def area(a, b, c):
            return cross(b[0] - a[0], b[1] - a[1], c[0] - a[0], c[1] - a[1])

        used, pt, top = [0] * (n + 1), [0] * (n + 2), 0
        for i in range(n):
            while top >= 2 and area(trees[pt[top - 1]], trees[pt[top]],
                                    trees[i]) > 0:
                used[pt[top]] = 0
                top -= 1
            used[i] = 1
            pt[top + 1] = i
            top += 1
        used[0] = 0
        for i in range(n - 1, -1, -1):
            if used[i] == 1: continue
            while top >= 2 and area(trees[pt[top - 1]], trees[pt[top]],
                                    trees[i]) > 0:
                used[pt[top]] = 0
                top -= 1
            used[i] = 1
            pt[top + 1] = i
            top += 1
        top -= 1
        res = []
        for i in range(1, top + 1):
            res.append(trees[pt[i]])
        return res
