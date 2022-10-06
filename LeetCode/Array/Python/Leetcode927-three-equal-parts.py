class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        acc = sum(arr)
        if not acc: return [0, 2]
        if acc % 3: return [-1, -1]
        avg, n = acc // 3, len(arr)
        s, p = [1, avg, avg + 1, 2 * avg, 2 * avg + 1, 3 * avg], [0] * 6
        c, j = 0, 0
        for i in range(n):
            if arr[i] == 0: continue
            c += 1
            while j < 6 and s[j] == c:
                p[j] = i
                j += 1
        last0 = n - 1 - p[5]
        dis1, dis2 = p[2] - p[1] - 1, p[4] - p[3] - 1
        if dis1 < last0 or dis2 < last0: return [-1, -1]
        if arr[p[0]:p[1]] != arr[p[2]:p[3]]: return [-1, -1]
        if arr[p[2]:p[3]] != arr[p[4]:p[5]]: return [-1, -1]
        return [p[1] + last0, p[3] + last0 + 1]
