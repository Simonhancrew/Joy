var numSpecial = function(mat) {
    const [n,m] = [mat.length,mat[0].length];
    let [c,r] = [new Array(m).fill(0),new Array(n).fill(0)];
    for(let i = 0;i < n;i++) {
        for(let j = 0;j < m;j++) {
            c[j] += mat[i][j];
            r[i] += mat[i][j];
        }
    }
    let ans = 0;
    for(let i = 0;i < n;i++) {
        for(let j = 0;j < m;j++) {
            if(mat[i][j] == 1 && c[j] == 1 && r[i] == 1) {
                ans++;
            }
        } 
    }
    return ans;
};