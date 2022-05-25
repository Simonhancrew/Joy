var findSubstringInWraproundString = function (p) {
    let mp = new Map();
    for (let i = 0; i < p.length;) {
        // console.log(i);
        let j = i + 1;
        while (j < p.length && (p[j].charCodeAt() - p[j - 1].charCodeAt() == 1 || (p[j] === 'a' && p[j - 1] === 'z'))) j++;
        // console.log(j);
        while (i < j) {
            mp.set(p[i], Math.max(mp.get(p[i]) || 0, j - i));
            i++;
        }
    }
    // console.log(mp);
    let res = 0;
    for (const it of mp.values()) res += it;
    return res;
};