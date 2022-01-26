var findNthDigit = function(n) {
    let cnt = 1,base = 9,s = 1;
    while(n > cnt * base){
        n -= cnt * base;
        cnt++;
        base *= 10;
        s *= 10;
    }
    s += Math.floor((n + cnt - 1) / cnt) - 1;
    n = n % cnt ? n % cnt : cnt;
    return String(s).codePointAt(n - 1) - '0'.codePointAt(0);
};