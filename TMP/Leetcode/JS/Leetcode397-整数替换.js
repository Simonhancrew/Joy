var integerReplacement = function(n) {
    let f = new Map();
    let dp = function(n) {
        if(f.has(n)) return f[n];
        if(n == 1) return 0;
        if(n % 2 == 0){
            return f[n] = dp(n / 2) + 1;   
        }
        return f[n] = Math.min(dp(n + 1),dp(n - 1)) + 1;
    }
    return dp(n);
};