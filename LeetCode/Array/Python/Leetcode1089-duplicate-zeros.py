class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        n,i,j,cnt = len(arr),0,0,0
        while cnt < n:
            if arr[i]:
                cnt += 1
            else:
                cnt += 2
            i += 1
        i -= 1
        j = n - 1
        if cnt == n + 1:
            arr[j] = 0
            j -= 1
            i -= 1
        while j >= 0:
            arr[j] = arr[i]
            j -= 1
            if arr[i] == 0:
                arr[j] = 0
                j -= 1
            i -= 1
        