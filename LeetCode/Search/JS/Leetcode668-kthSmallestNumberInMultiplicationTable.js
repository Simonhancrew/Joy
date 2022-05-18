var findKthNumber = function (m, n, k) {
    let [l, r] = [1, n * m];
    let get = function (mid, m, n) {
        let res = 0;
        for (let i = 1; i <= n; i++) {
            res += Math.min(m, parseInt(mid / i));
        }
        return res;
    }

    while (l < r) {
        const mid = l + r >> 1;
        if (get(mid, m, n) >= k) r = mid;
        else l = mid + 1;
    }
    return l;
};