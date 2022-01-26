class Solution:
    def simplifyPath(self, s: str) -> str:
        if s[-1] != '/': s += '/'
        res,name = '',''
        for ch in s:
            if ch != '/': name += ch
            else:
                if name == '..':
                    while res and res[-1] != '/': res = res[:-1]
                    if res: res = res[:-1]
                elif name != '.' and name != '':
                    res += '/' + name
                name = ''
        if not res: res = '/'
        return res