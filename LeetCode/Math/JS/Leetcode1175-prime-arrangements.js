var numPrimeArrangements = function (n) {
    let [st, primes] = [new Array(n + 1).fill(false), []];
    const P = parseInt(1e9 + 7);
    for (let i = 2; i <= n; i++) {
        if (!st[i]) primes.push(i);
        for (let j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    let cnt = primes.length;
    let res = 1;
    let m = n - cnt;
    while (cnt > 0) {
        res = res % P;
        res *= cnt;
        cnt--;
    }
    while (m > 0) {
        res = res % P;
        res *= m;
        m--;
    }
    return res % P;
};