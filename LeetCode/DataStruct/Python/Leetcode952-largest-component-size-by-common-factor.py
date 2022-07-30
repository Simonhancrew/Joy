class Solution:
    def largestComponentSize(self, nums: List[int]) -> int:
        n,res = len(nums),1
        cnt,fa = [1] * n,[i for i in range(n)]
        def find(x):
            if fa[x] != x: fa[x] = find(fa[x])
            return fa[x]
        app = defaultdict(list)
        for i in range(n):
            x,j = nums[i],1
            while j <= x // j:
                if x % j == 0:
                    if j > 1: app[j].append(i)
                    app[x // j] .append(i)
                j += 1
        for v in app.values():
            for i in range(1,len(v)):
                a,b = v[0],v[i]
                if find(a) != find(b):
                    cnt[find(a)] += cnt[find(b)]
                    fa[find(b)] = find(a)
                    if res < cnt[find(a)]:
                        res = cnt[find(a)]
        return res