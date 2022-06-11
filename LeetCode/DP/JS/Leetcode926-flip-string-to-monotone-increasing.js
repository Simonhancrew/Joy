var minFlipsMonoIncr = function (s) {
    let [f0, f1] = [0, 0];
    for (const c of s) {
        let [ff0, ff1] = [f0, Math.min(f0, f1)];
        ff0 += (c === '1') ? 1 : 0;
        ff1 += (c === '0') ? 1 : 0;
        f0 = ff0;
        f1 = ff1;
    }
    return Math.min(f0, f1);
};