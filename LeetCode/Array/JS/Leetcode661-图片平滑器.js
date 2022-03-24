var imageSmoother = function(img) {
    const n = img.length,m = img[0].length;
    const res = new Array(n).fill(0).map(()=>new Array(m).fill(0));
    let get = function(x,y) {
        let acc = 0,div = 0;
        for(let i = -1;i <= 1;i++) {
            for(let j = -1;j <= 1;j++){
                const nx = x + i,ny = y + j;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                acc += img[nx][ny],div++; 
            }
        }
        return Math.floor(acc / div);
    }
    for(let i = 0;i < n;i++) {
        for(let j = 0;j < m;j++){
            res[i][j] = get(i,j);
        }
    }
    return res;
};