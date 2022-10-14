var distinctSubseqII = function (s) {
    const [n, P] = [s.length, parseInt(1e9 + 7)];
    let f = new Array(26).fill(0);
    f[s[0].charCodeAt() - 'a'.charCodeAt()] = 1;
    for (let i = 1; i < n; i++) {
        let rec = f[s[i].charCodeAt() - 'a'.charCodeAt()];
        rec = f.reduce((sum, cur) => sum + cur, 1) % P;
        f[s[i].charCodeAt() - 'a'.charCodeAt()] = rec;
    }
    return f.reduce((sum, cur) => sum + cur, 0) % P;
};