var findLongestChain = function(pairs) {
    pairs.sort((a,b) => a[0] - b[0]);
    const n = pairs.length;
    let f = new Array(n).fill(1);
    let ans = 1;
    for(let i = 1;i < n;i++) {
        for(let j = 0;j < i;j++) {
            if(pairs[i][0] > pairs[j][1]) f[i] = Math.max(f[i],f[j] + 1);
        }
        ans = Math.max(ans,f[i]);
    }
    return ans;
};
