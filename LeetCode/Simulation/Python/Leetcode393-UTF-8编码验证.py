class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        n = len(data)
        
        def get(a,b):
            return (a >> b) & 1
        i = 0
        while i < n:
            if get(data[i],7) == 0: 
                i += 1
                continue
            cnt = 0
            while(cnt <= 4 and get(data[i],7 - cnt) == 1): cnt += 1
            if cnt == 1 or cnt > 4: return False
            for j in range(1,cnt):
                t = i + j
                if t >= n: return False
                if not (get(data[t],7) == 1 and get(data[t],6) == 0): return False   
            i += cnt
        return True