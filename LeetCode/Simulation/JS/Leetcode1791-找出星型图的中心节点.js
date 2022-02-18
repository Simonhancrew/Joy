var findCenter = function(edges) {
    const n = edges.length + 1;
    const st = new Array(n + 1).fill(0);
    for(const e of edges){
        st[e[0]]++;
        st[e[1]]++;
    }
    for(let i = 1;i <= n;i++){
        if(st[i] == n - 1) return i;
    }
    return -1;
};