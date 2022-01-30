class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        st = defaultdict(int)
        for word in s1.split():
            st[word] += 1
        for word in s2.split():
            st[word] += 1
        ans = []
        for k,v in st.items():
            if v == 1: ans.append(k)
        return ans
