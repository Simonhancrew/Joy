var findKthNumber = function(n, k) {
    let pre = 1;
    let f = function(pre,n) {
        let a = String(n),b = String(pre);
        const d = a.length - b.length;
        let res = 0,p = 1;
        for(let i = 0;i < d;i++) {
            res += p;
            p *= 10;
        }
        if(a.substr(0,b.length) == b) res += n - pre * p + 1;
        else if(a.substr(0,b.length) > b) res += p;
        return res;
    }
    while(k > 1) {
        const cnt = f(pre,n);
        if(k > cnt) {
            k -= cnt;
            pre++;
        }else{
            pre *= 10;
            k--;
        }
    }
    return pre;
};