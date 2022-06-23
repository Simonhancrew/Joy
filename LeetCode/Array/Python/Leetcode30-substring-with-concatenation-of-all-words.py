class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n,m,w = len(s),len(words),len(words[0])
        rec,res = defaultdict(int),[]
        if not words: return res
        for ss in words: 
            rec[ss] += 1

        for i in range(w):
            tmp,cnt,j = defaultdict(int),0,i
            while j + w <= n:
                if j >= i + m * w:
                    t = s[j - m * w:j - m * w + w]
                    tmp[t] -= 1
                    if tmp[t] < rec[t]: cnt -= 1
                t = s[j:j + w]
                tmp[t] += 1
                if tmp[t] <= rec[t]: cnt += 1
                if cnt == m: res.append(j - (m - 1) * w)
                j += w            
        
        return res