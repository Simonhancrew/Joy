class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator % denominator == 0: return str(numerator // denominator)
        up,down = abs(numerator),abs(denominator)
        ans = "-" if (numerator < 0) ^ (denominator < 0) else ''
        ans += str(up // down) + '.'
        st = dict()
        up = up % down * 10
        while up != 0:
            if up in st:
                ans = ans[:st[up]] + '(' + ans[st[up]:]
                ans += ')'
                break
            st[up] = len(ans)
            ans += str(up // down)
            up = up % down * 10
        return ans