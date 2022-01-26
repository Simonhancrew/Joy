class Solution:
    def compareVersion(self, v1: str, v2: str) -> int:
        a = list(v1.split('.'))
        b = list(v2.split('.'))
        i = j = 0
        while i < len(a) or j < len(b):
            x = y = 0
            if i >= len(a):
                x = 0
            else:
                x = int(a[i])
            if j >= len(b):
                y = 0
            else:
                y = int(b[j])
            if x < y:
                return -1
            elif x > y:
                return 1
            i += 1
            j += 1
        return 0