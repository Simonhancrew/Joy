class trie:
    def __init__(self):
        self.son = defaultdict(trie)
        self.flag = False

    def insert(self, s):
        node = self
        for ch in s:
            if not node.son[ch]: node.son[ch] = trie()
            node = node.son[ch]
        node.flag = True

    def query(self, s):
        node = self
        for i, ch in enumerate(s):
            if not node.son[ch]: return s
            node = node.son[ch]
            if node.flag: return s[:i + 1]
        return s


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        root = trie()
        for word in dictionary:
            root.insert(word)
        res = []
        for word in sentence.split(' '):
            res.append(root.query(word))
        return ' '.join(res)
