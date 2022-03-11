var countHighestScoreNodes = function (parents) {
    const n = parents.length;
    const sz = new Array(n).fill(0), g = new Array(n).fill(0).map(() => []);
    let cnt = 0, mx = -1;
    for (let i = 1; i < n; i++) {
        g[parents[i]].push(i);
    }
    let dfs = function (u) {
        sz[u] = 1;
        let tmp = 1;
        for (const s of g[u]) {
            dfs(s);
            sz[u] += sz[s];
            tmp *= sz[s];
        }
        if (n - sz[u] > 0) tmp *= n - sz[u];
        if (tmp > mx) {
            mx = tmp;
            cnt = 1;
        } else if (tmp == mx) {
            cnt++;
        }
        // console.log(u,cnt,sz[u],tmp);
    }
    dfs(0);
    return cnt;
};