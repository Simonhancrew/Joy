class Solution:
    def countValidWords(self, sentence: str) -> int:
        words = sentence.split()
        res = 0
        def check(word):
            cnt1,cnt2=0,0
            for i,ch in enumerate(word):
                if ch.isdigit():
                    return False
                if ch =='-':
                    cnt1 += 1
                    if cnt1 > 1 or i == 0 or i == len(word) - 1:
                        return False
                    if ord(word[i-1]) < ord('a') or ord(word[i + 1]) < ord('a'):
                        return False
                    if ord(word[i-1]) > ord('z') or ord(word[i + 1]) > ord('z'):
                        return False
                elif ch in ['!','.',',']:
                    cnt2 += 1
                    if cnt2 > 1 or word[-1] != ch: return False
                elif ch == '/':continue
                elif ord(ch) >= ord('a') and ord(ch) <= ord('z'):continue
                else: return False
            return True
        for word in words:
            if(check(word)): res+=1
        return res