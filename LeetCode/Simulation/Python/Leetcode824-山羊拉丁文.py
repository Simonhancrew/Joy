class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        s = sentence.split(' ')
        st, cur = set("aeiou"), 'a'
        print(st)
        for i in range(len(s)):
            if s[i][0] in st or s[i][0].lower() in st:
                s[i] += 'ma'
            else:
                s[i] = s[i][1:] + s[i][0] + 'ma'
            s[i] += cur
            cur += 'a'
        return ' '.join(s)
