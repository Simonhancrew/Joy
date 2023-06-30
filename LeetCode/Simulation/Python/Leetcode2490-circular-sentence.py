class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        rec = sentence.split(' ')
        n = len(rec)
        for i in range(n - 1):
            if rec[i][-1] != rec[i + 1][0]:
                return False
        return rec[-1][-1] == rec[0][0]