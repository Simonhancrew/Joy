class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        n,i,j = len(start),0,0
        while True:
            while i < n and start[i] == 'X': i += 1
            while j < n and end[j] == 'X': j += 1
            
            if i == n or j == n:
                break
            
            if start[i] != end[j]:
                return False
            if start[i] == 'L' and i < j:
                return False 
            if end[j] == 'R' and i > j:
                return False
            i += 1
            j += 1
        return i == n and j == n