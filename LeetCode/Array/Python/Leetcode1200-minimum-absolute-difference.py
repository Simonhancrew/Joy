class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        n, res, mini = len(arr), [], 1 << 31
        for i in range(n - 1):
            diff = arr[i + 1] - arr[i]
            if diff == mini:
                res.append([arr[i], arr[i + 1]])
            elif diff < mini:
                mini = diff
                res = [[arr[i], arr[i + 1]]]
        return res
