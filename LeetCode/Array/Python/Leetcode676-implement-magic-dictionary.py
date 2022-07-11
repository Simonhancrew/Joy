class MagicDictionary:

    def __init__(self):
        self.rec = []

    def buildDict(self, dictionary: List[str]) -> None:
        self.rec = dictionary

    def search(self, searchWord: str) -> bool:
        for pa in self.rec:
            if len(pa) != len(searchWord): continue
            diff = 0
            for i in range(len(pa)):
                if pa[i] != searchWord[i]: diff += 1
                if diff > 1: break
            if diff == 1:
                return True
        return False
