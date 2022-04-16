var largestPalindrome = function (n) {
    if (n == 1) return 9;
    const base = 10 ** n - 1;
    for (let x = base; ; x--) {
        let right = x.toString().split('').reverse().join('');
        let p = BigInt(x.toString() + right);
        let y = BigInt(base);
        while (y * y >= p) {
            if (p % y == BigInt(0)) return p % BigInt(1337);
            y--;
        }
    }
};