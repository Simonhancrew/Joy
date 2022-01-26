var findJudge = function(n, trust) {
    let din = new Array(n + 1).fill(0),dout = new Array(n + 1).fill(0);
    let res = -1;
    for(const p of trust){
        let a = p[0],b = p[1];
        din[b]++;
        dout[a]++;
    }
    for(let i = 1;i <= n;i++){
        if(dout[i] == 0 && din[i] == n - 1) {
            if(res != -1) return -1;
            res = i;
        }
    }
    return res;
};