class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mp = defaultdict(int)
        for ch in magazine:
            mp[ch] += 1
        for ch in ransomNote:
            if ch in mp and mp[ch] != 0:
                mp[ch] -= 1
            else:
                return False
        return True