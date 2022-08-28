var preimageSizeFZF = function(k) {
    let calcu = function(k) {
        let [l,r] = [-1,1e18];
        while (l < r) {
            const mid = Math.floor((l + r + 1) / 2);
            if(f(mid) <= k) l = mid;
            else r = mid - 1;
        }
        return r;
    }

    let f = function(x) {
        let res = 0;
        while(x != 0) {
            res += Math.floor(x / 5);
            x = Math.floor(x / 5);
        }
        return res;
    }
    return calcu(k) - calcu(k - 1);
};