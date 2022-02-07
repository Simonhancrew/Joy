class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        heap,ans = [],[]
        if a > 0: heap.append([-a,'a'])
        if b > 0: heap.append([-b,'b'])
        if c > 0: heap.append([-c,'c'])
        heapq.heapify(heap)
        while len(heap) > 0:
            cur = heapq.heappop(heap)
            ch,cnt = cur[1],-cur[0]
            if len(ans) >= 2 and ans[-1] == ans[-2] == ch:
                if len(heap) == 0: break
                ne = heapq.heappop(heap)
                chne,cntne= ne[1],-ne[0]
                ans.append(chne)
                cntne -= 1
                if cntne > 0: heapq.heappush(heap,[-cntne,chne])
                heapq.heappush(heap,cur)
            else:
                ans.append(ch)
                cnt -= 1
                if cnt > 0: heapq.heappush(heap,[-cnt,ch])
        return ''.join(ans)