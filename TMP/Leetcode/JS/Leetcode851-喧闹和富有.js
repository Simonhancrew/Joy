var loudAndRich = function(richer, quiet) {
    let n = quiet.length;
    let ans = new Array(n).fill(-1);
    let g = new Array(n).fill(0).map(() => []);
    for(const rich of richer) {
        let a = rich[0],b = rich[1];
        g[b].push(a);
    }
    let dfs = function(u) {
        if(ans[u] != -1) return
        ans[u] = u;
        for(const v of g[u]){
            dfs(v);
            if(quiet[ans[v]] < quiet[ans[u]]){
                ans[u] = ans[v];
            }
        }
    }
    for(let i = 0;i < n;i++) dfs(i);
    return ans;
}