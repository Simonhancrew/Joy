var findMinDifference = function(timePoints) {
    const trans = []
    for(const s of timePoints) {
        let h = +s.slice(0,2),m = +s.slice(3);
        trans.push(h * 60 + m);
    }
    trans.sort((a,b)=>a-b);
    const n = trans.length;
    let ans = Number.MAX_VALUE
    for(let i = 0;i < n - 1;i++) {
        ans = Math.min(ans,trans[i + 1] - trans[i]);
    }
    ans = Math.min(ans,trans[0] + 1440 - trans[n - 1]);
    return ans;
};