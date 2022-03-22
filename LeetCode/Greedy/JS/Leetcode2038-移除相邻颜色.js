var winnerOfGame = function(colors) {
    let cur = 'C',f = [0,0],cnt = 1;
    for(const c of colors){
        if(cur != c){
            cur = c;
            cnt = 1
        }else{
            cnt++
            if(cnt >= 3) f[cur.charCodeAt(0) - 'A'.charCodeAt(0)]++;
        }
    }
    return f[0] > f[1];
};