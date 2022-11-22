const MOD = 1000000007;
var nthMagicalNumber = function(n, a, b) {
    let l = Math.min(a, b);
    let r = n * Math.min(a, b);
    const c = lcm(a, b);
    while (l < r) {
        const mid = Math.floor((l + r) / 2);
        const cnt = Math.floor(mid / a) + Math.floor(mid / b) - Math.floor(mid / c);
        if (cnt >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l % MOD;
}

const lcm = (a, b) => {
    return Math.floor(a * b / gcd(a, b));
}

const gcd = (a, b) => {
    return b !== 0 ? gcd(b, a % b) : a;
};
