var superPow = function(a, b) {
    let p = 1337
    let qmi = function(a,b){
        a %= p;
        let res = 1;
        while(b) {
            if(b & 1) res = res * a % p;
            b >>= 1;
            a = a * a % p;
        }
        return res;
    }
    if(b.length == 0) return 1;
    let k = b.pop();
    return qmi(superPow(a,b),10) * qmi(a,k) % p;
};