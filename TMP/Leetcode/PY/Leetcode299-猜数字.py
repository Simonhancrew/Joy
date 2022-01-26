class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        st = defaultdict(int)
        bull,cow = 0,0
        for i in range(len(secret)):
            if(secret[i] == guess[i]): bull+=1
            else: st[secret[i]] += 1
        for i in range(len(guess)):
            if secret[i] != guess[i] and st[guess[i]] != 0:
                cow += 1
                st[guess[i]] -= 1
        return str(bull) + 'A' + str(cow) + 'B'