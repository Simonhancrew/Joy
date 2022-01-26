class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        heap,ans,time,n = [],0,0,len(apples)
        while len(heap) or time < n:
            if time < n and apples[time] > 0:
                heapq.heappush(heap,[time + days[time] - 1,apples[time]])
            while len(heap) and heap[-1][0] < time: heapq.heappop(heap)
            if len(heap):
                t = heapq.heappop(heap)
                ans += 1
                t[1] -= 1
                if t[0] > time and t[1] > 0:
                    heapq.heappush(heap,t)
            time += 1
        return ans  