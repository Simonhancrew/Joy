class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        l,r = 0,1
        eps = 1e-8
        def get(mid):
            j,res,n = 0,0,len(arr)
            for i in range(n):
                while j + 1 < n and arr[j + 1] / arr[i] <= mid: j += 1
                if (arr[j] / arr[i]) <= mid: res += (j + 1)
                if abs(arr[j] / arr[i] - mid) <= eps:
                    self.a,self.b = arr[j],arr[i]
            return res
        while r - l > eps:
            mid = (l + r) / 2
            # print(mid)
            if get(mid) >= k: r = mid
            else: l = mid
        return [self.a,self.b]