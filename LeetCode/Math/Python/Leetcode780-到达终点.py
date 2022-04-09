class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while tx > sx and ty > sy:
            if ty > tx: ty %= tx
            else: tx %= ty
        
        if tx < sx or ty < sy: return False
        
        if tx == sx: 
            return (ty - sy) % tx == 0
        
        return (tx - sx) % ty == 0