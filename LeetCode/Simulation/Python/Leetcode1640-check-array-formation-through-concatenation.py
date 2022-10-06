class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        mp = defaultdict(int)
        for i, val in enumerate(pieces):
            mp[val[0]] = i
        i = 0
        while i < len(arr):
            if arr[i] not in mp: return False
            tmp, size = pieces[mp[arr[i]]], len(pieces[mp[arr[i]]])
            # print(arr[i])
            if tmp != arr[i:i + size]: return False
            i += size
        return True
