var Solution = function (n, blacklist) {
    this.n = n;
    this.m = blacklist.length;
    this.mp = new Map();
    let m = blacklist.length;
    let st = new Set();
    for (let i = n - m; i < n; i++) st.add(i);
    for (const x of blacklist) st.delete(x);
    let it = st[Symbol.iterator]();
    for (const x of blacklist) {
        if (x < n - m) this.mp.set(x, it.next().value);
    }
};

Solution.prototype.pick = function () {
    let k = parseInt(Math.random() * (this.n - this.m));
    if (this.mp.has(k)) {
        return this.mp.get(k);
    }
    return k;
};
