class Solution:
    def originalDigits(self, s: str) -> str:
        name = ["zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"]
        rank = [0,8,3,2,6,4,5,1,7,9]
        mp = defaultdict(int)
        for ch in s: mp[ch] += 1
        res = []
        for x in rank:
            flag = True
            while flag:
                for ch in name[x]:
                    if mp[ch] == 0: 
                        flag = False
                        break
                if flag:
                    res.append(str(x))
                    for ch in name[x]: mp[ch] -= 1
        res.sort()
        return ''.join(res)