class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        ans = []
        for i in range(1,n - k): 
            ans.append(i)
        i,j = n - k,n
        while i <= j:
            ans.append(i)
            if i != j: ans.append(j)
            i += 1
            j -= 1
        return ans
