var trailingZeroes = function(n) {
    let res = 0;
    while(n) {
        res += Math.floor(n / 5);
        n = Math.floor(n / 5);
    }
    return res;
};