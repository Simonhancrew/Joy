class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        mp = [
            ['q','w','e','r','t','y','u','i','o','p'],
            ['a','s','d','f','g','h','j','k','l'],
            ['z','x','c','v','b','n','m']
        ]
        res = []
        for word in words:
            for i in range(3):
                flag = True
                for ch in word:
                    if ch not in mp[i] and ch.lower() not in mp[i]:
                        flag = False
                        break
                if flag:
                    res.append(word)
                    break
        return res