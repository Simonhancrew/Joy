class Solution:
    def pivotInteger(self, n: int) -> int:
      p = [0] * (n + 1)
      for i in range(1, n + 1):
        p[i] = p[i - 1] + i
      for i in range(1, n + 1):
        if p[i] - p[0] == p[n] - p[i - 1]:
          return i
      return -1
