var largestComponentSize = function (nums) {
    let [n, res] = [nums.length, 1];
    let [fa, cnt] = [new Array(n).fill(0), new Array(n).fill(1)];
    for (let i = 0; i < n; i++) {
        fa[i] = i;
    }
    let app = new Map();
    for (let i = 0; i < n; i++) {
        const x = nums[i];
        for (let j = 1; j <= Math.floor(x / j); j++) {
            if (x % j == 0) {
                if (j > 1) {
                    if (!app.get(j)) app.set(j, [i]);
                    else app.get(j).push(i);
                }
                if (j == Math.floor(x / j)) continue;
                if (!app.get(Math.floor(x / j))) app.set(Math.floor(x / j), [i]);
                else app.get(Math.floor(x / j)).push(i);
            }
        }
    }
    let find = (x) => {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }

    for (let v of app.values()) {
        for (let i = 1; i < v.length; i++) {
            let [a, b] = [v[0], v[i]];
            if (find(a) != find(b)) {
                cnt[find(a)] += cnt[find(b)];
                fa[find(b)] = find(a);
                res = Math.max(res, cnt[find(a)]);
            }
        }
    }
    return res;
};