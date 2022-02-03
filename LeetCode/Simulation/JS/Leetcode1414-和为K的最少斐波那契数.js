var findMinFibonacciNumbers = function(k) {
    const f = [1,1];
    let pre = 1,aft = 1;
    while(aft < k) {
        const t = aft;
        aft = aft + pre;
        pre = t;
        f.push(aft);
    }
    let cnt = 0,idx = f.length - 1;
    while(k) {
        while(f[idx] <= k) k -= f[idx],cnt++;
        idx--;
    }
    return cnt;
};