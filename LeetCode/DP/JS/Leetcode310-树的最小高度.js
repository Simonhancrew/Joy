var findMinHeightTrees = function (n, edges) {
    const g = new Array(n).fill(0).map(() => []);
    const d1 = new Array(n).fill(0), d2 = new Array(n).fill(0), p1 = new Array(n).fill(0), up = new Array(n).fill(0);
    for (const ed of edges) {
        a = ed[0], b = ed[1];
        g[a].push(b), g[b].push(a);
    }

    let dfs1 = function (u, fa) {
        for (const x of g[u]) {
            if (x == fa) continue;
            dfs1(x, u);
            const d = d1[x] + 1;
            if (d >= d1[u]) {
                d2[u] = d1[u], d1[u] = d;
                p1[u] = x;
            } else if (d > d2[u]) {
                d2[u] = d;
            }
        }
    }

    let dfs2 = function (u, fa) {
        for (const x of g[u]) {
            if (x == fa) continue;
            if (p1[u] == x) up[x] = Math.max(up[u], d2[u]) + 1;
            else up[x] = Math.max(up[u], d1[u]) + 1;
            dfs2(x, u);
        }
    }

    dfs1(0, -1);
    dfs2(0, -1);

    let mind = n + 1, res = [];
    for (let i = 0; i < n; i++) mind = Math.min(mind, Math.max(up[i], d1[i]));
    for (let i = 0; i < n; i++) {
        if (Math.max(up[i], d1[i]) == mind) {
            res.push(i);
        }
    }
    return res;
};