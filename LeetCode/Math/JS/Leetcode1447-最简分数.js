var simplifiedFractions = function(n) {
    let gcd = function(a,b) {
        return b ? gcd(b,a % b) : a;
    }
    const ans = [];
    for(let i = 2;i <= n;i++) {
        for(let j = 1;j < i;j++) {
            if(gcd(i,j) == 1) ans.push(j + '/' + i);
        }
    }
    return ans;
};