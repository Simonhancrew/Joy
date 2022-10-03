class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        cnt,flag = 0,False
        for i in s:
            if i == '1':
                if flag: continue
                else:
                    cnt += 1
                    if cnt > 1: return False
                    flag = True
            else:
                flag = False
        return True