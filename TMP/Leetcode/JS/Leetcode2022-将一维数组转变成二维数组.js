var construct2DArray = function(original, m, n) {
    if(original.length != m * n) return [];
    const ans = [];
    for(let i = 0;i < m;i++){
        const t = [];
        for(let j = 0;j < n;j++){
            t.push(original[i * n + j]);
        }
        ans.push(t);
    }
    return ans;
};