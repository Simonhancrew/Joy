class Codec:
    def __init__(self):
        self.mp = defaultdict(str)
        self.pa = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

    def getRandom(self,n):
        res = ''
        for i in range(n):
            res += self.pa[randrange(62)]
        return res

    def encode(self, longUrl: str) -> str:
        while True:
            short_url = self.getRandom(6)
            if short_url in self.mp: continue
            self.mp[short_url] = longUrl
            return "http://hh.com/" + short_url
        return  ''
        

    def decode(self, shortUrl: str) -> str:
        return self.mp[shortUrl[14:]]
