class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        mp = defaultdict(int)
        for ch in licensePlate:
            if ch == ' ' or ch.isdigit(): continue
            mp[ch.lower()] += 1
        res = ''
        def check(mp,st):
            for k,v in mp.items():
                if st[k] < v: return False
            return True
        for stri in words:
            st = defaultdict(int)
            for ch in stri:
                st[ch] += 1
            if check(mp,st):
                if len(res) == 0 or len(res) > len(stri):
                    res = stri
        return res 