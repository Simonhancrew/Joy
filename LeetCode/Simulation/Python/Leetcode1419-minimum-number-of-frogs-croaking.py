class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
      cnt, pre = [0] * 5, [0] * 5
      mp = defaultdict(int)
      pa, rev = "croak", 'croakc'
      for (i, c) in enumerate(pa):
        mp[c] = i
      for i in range(1, 6):
        cur, last = rev[i], rev[i - 1]
        pre[mp[cur]] = mp[last]
      for c in croakOfFrogs:
        idx, last_idx = mp[c], pre[mp[c]]
        if cnt[last_idx] != 0:
          cnt[last_idx] -= 1
        elif idx != 0:
          return -1
        cnt[idx] += 1
      for i in range(4):
        if cnt[i] != 0:
          return -1
      return cnt[4]