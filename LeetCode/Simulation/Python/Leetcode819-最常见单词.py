class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        ban = set(banned)
        freq = Counter()
        word, n = "", len(paragraph)
        for i in range(n + 1):
            if i < n and paragraph[i].isalpha():
                word += paragraph[i].lower()
            elif word:
                if word not in ban:
                    freq[word] += 1
                word = ""
        maxFreq = max(freq.values())
        return next(word for word, f in freq.items() if f == maxFreq)