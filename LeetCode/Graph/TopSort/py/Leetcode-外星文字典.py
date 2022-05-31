class Solution:
    def alienOrder(self, words: List[str]) -> str:
        mp,n,flag = defaultdict(list),len(words), True
        din = defaultdict(int)
        for word in words:
            for i in range(len(word)):
                c = word[i]
                if c not in mp:
                    mp[c] = []


        def build(l,r):
            nonlocal flag
            n = min(len(l),len(r))
            i =  0
            while i < n:
                a,b = l[i],r[i]
                if a != b:
                    mp[a].append(b)
                    din[b] += 1
                    break
                i += 1
            if i == n and len(l) > len(r):
                flag = False
    
        for i in range(1,n):
            build(words[i - 1],words[i])
            if not flag: break


        if not flag: return ''

        res = []        
        def topsort():
            nonlocal res
            q,cnt = deque(),0
            for k,v in mp.items():
                if k not in din:
                    q.append(k)

            while q:
                t = q.popleft()
                res.append(t)
                cnt += 1
                for ne in mp[t]:
                    din[ne] -= 1
                    if din[ne] == 0:
                        q.append(ne)

            if cnt != len(mp): return True
            return False

        if topsort(): return ''

        return ''.join(res) 