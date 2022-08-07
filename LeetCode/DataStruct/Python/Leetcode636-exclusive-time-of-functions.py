class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        ans,stk,last = [0] * n,[],0
        for log in logs:
            x,y = log.find(':'),log.rfind(':')
            id,ts = int(log[:x]),int(log[y + 1:])
            if log[x + 1:y] == "start":
                if stk:
                    ans[stk[-1]] += ts - last
                stk.append(id)
                last = ts
            else:
                ans[stk[-1]] += ts - last + 1
                last = ts + 1
                stk.pop()
        return ans