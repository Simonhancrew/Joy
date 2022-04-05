var countPrimeSetBits = function(left, right) {
    const primes = [],st = new Array(34).fill(false);
    let get_primes = function(n) {
        st[1] = true;
        for(let i = 2;i <= n;i++) {
            if(!st[i]) primes.push(i);
            for(let j = 0;primes[j] <= Math.floor(n / i);j++) {
                st[primes[j] * i] = true;
                if(i % primes[j] == 0) break;
            }
        }
    }
    let check = function(n) {
        let cnt = 0;
        while(n) {
            n -= (n & -n);
            cnt++;
        }
        return !st[cnt];
    }
    get_primes(33);
    let ans = 0;
    for(let i = left;i <= right;i++) {
        if(check(i)) ans++;
    }
    return ans;
};  