class Solution:
    def fractionAddition(self, expression: str) -> str:
        n,i,up,down = len(expression),0,0,1

        while i < n:
            sign,up1,down1 = 1,0,0
            if expression[i] == '-' or expression[i] == '+':
                sign = -1 if expression[i] == '-' else 1
                i += 1
            while i < n and expression[i].isdigit():
                up1 = up1 * 10 + ord(expression[i]) - ord('0') 
                i += 1
            up1 = sign * up1

            i += 1
            while i < n and expression[i].isdigit():
                down1 = down1 * 10 + ord(expression[i]) - ord('0')
                i += 1
            up = up1 * down + up * down1
            down *= down1
        if up == 0: return '0/1'
        g = gcd(abs(up),down)
        return "{}/{}".format(up // g,down // g)            
