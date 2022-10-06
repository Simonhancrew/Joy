class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        pos = [
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
            "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
        ]
        st = set()
        for w in words:
            s = ''
            for v in w:
                s += pos[ord(v) - ord('a')]
            st.add(s)
        return len(st)
