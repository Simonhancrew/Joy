class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        mp = defaultdict(list)
        for i, c in enumerate(s):
            mp[c].append(i)
        
        ans = len(words)
        for x in words:
            if len(x) > len(s):
                ans -= 1
                continue
            idx = -1
            for c in x:
                arr = mp[c]
                it = bisect_right(arr,idx)
                if it == len(arr):
                    ans -= 1
                    break
                idx = arr[it]
        return ans