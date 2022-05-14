var minStickers = function(stickers, target) {
    let n = target.length;
    const f = new Array((1 << n) - 1).fill(-1);
    f[(1 << n) - 1] = 0;
    let dp = function(st){
        if(f[st] != -1) return f[st];
        if(st == ((1 << n) - 1)) {
            return 0;
        }
        f[st] = n + 1;
        for(const s of stickers) {
            let t = st;
            let cnt = new Array(26).fill(0);
            for(const c of s) {
                cnt[c.charCodeAt() - 'a'.charCodeAt()]++;
            }
            for(let i = 0;i < target.length;i++) {
                let c = target[i];
                if(((t >> i) & 1) == 0 && cnt[c.charCodeAt() - 'a'.charCodeAt()] > 0) {
                    cnt[c.charCodeAt() - 'a'.charCodeAt()]--;
                    t += (1 << i);
                }
            }
            if(t == st) continue;
            f[st] = Math.min(f[st],dp(t) + 1);
        }
        return f[st];
    }

    let res = dp(0);
    if(res >= n + 1) return -1;
    return res;
};