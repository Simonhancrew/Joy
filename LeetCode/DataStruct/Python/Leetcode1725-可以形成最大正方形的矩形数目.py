class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        st = defaultdict(int)
        for edge in rectangles:
            st[min(edge[0],edge[1])] += 1
        mx,cnt = -1,0
        for k,v in st.items():
            if k > mx:
                mx,cnt = k,v
        return cnt