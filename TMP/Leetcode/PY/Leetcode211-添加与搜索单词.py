class Node:
    def __init__(self):
        self.child = [None] * 26
        self.isend = False 

class WordDictionary:

    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        p = self.root
        for i in range(len(word)):
            c = ord(word[i]) - ord('a')
            if not p.child[c]:
                p.child[c] = Node()
            p = p.child[c]
        p.isend = True 

    def search(self, word: str) -> bool:
        p = self.root
        def dfs(p,word,idx):
            if idx == len(word): return p.isend
            if word[idx] == '.':
                for i in range(26):
                    if p.child[i] and dfs(p.child[i],word,idx+1):
                        return True
            else:
                c = ord(word[idx]) - ord('a')
                if p.child[c]:
                    return dfs(p.child[c],word,idx+1)
            return False
        return dfs(p,word,0)