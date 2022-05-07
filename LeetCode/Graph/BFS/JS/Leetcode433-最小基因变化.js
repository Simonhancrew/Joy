var minMutation = function (start, end, bank) {
    let [st, dist, q] = [new Set(bank), new Map(), []];
    const id = ['A', 'G', 'C', 'T'];
    dist.set(start, 0);
    q.push(start);
    while (q.length != 0) {
        const t = q.shift();
        for (let i = 0; i < 8; i++) {
            let s = [...t];
            for (const x of id) {
                s[i] = x;
                ss = s.join('');
                if (st.has(ss) && !dist.has(ss)) {
                    dist.set(ss, dist.get(t) + 1);
                    if (ss === end) return dist.get(ss);
                    q.push(ss);
                }
            }
        }
    }
    return -1;
};