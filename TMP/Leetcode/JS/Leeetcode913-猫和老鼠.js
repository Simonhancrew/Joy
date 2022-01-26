/**
 * @param {number[][]} graph
 * @return {number}
 */
 var catMouseGame = function(g) {
    const n = g.length;
    const f = new Array(2 * n + 3).fill(0).map(() => new Array(n).fill(0).map(()=>new Array(n).fill(-1)))
    let dp = function(k,i,j){
        let v = f[k][i][j];
        if(k > 2 * n){
            f[k][i][j] = 0;
            return 0;
        }
        if(v != -1) {
            return v;
        }
        if(i == 0) {
            f[k][i][j] = 1;
            return 1; 
        }
        if(i == j) {
            f[k][i][j] = 2;
            return 2;
        }
        let draws = 0;
        if(k % 2 == 0) {
            for(const x of g[i]){
                const t = dp(k + 1,x,j);
                if(t == 1) {
                    f[k][i][j] = 1;
                    return 1;
                }
                if(t == 0) draws++;
            }
            if(draws != 0) {
                f[k][i][j] = 0;
                return 0;
            }
            f[k][i][j] = 2;
            return 2;
        }
        for(const x of g[j]){
            if(x == 0) continue;
            const t = dp(k + 1,i,x);
            if(t == 2) {
                f[k][i][j] = 2;
                return 2;
            }
            if(t == 0) draws++;           
        }
        if(draws != 0) {
            f[k][i][j] = 0;
            return 0;
        }
        f[k][i][j] = 1;
        return 1;
    }
    return dp(0,1,2)
};