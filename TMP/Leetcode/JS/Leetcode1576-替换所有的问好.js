var modifyString = function(s) {
    const rec = [...s];
    const n = s.length;
    for(let i = 0;i < n;i++){
        if(rec[i] == '?'){
            for(let j = 0;j < 3;j++){
                if ((i > 0 && rec[i - 1] === String.fromCharCode('a'.charCodeAt() + j)) || (i < n - 1 && rec[i + 1] === String.fromCharCode('a'.charCodeAt() + j))) {
                    continue;
                }
                rec[i] = String.fromCharCode('a'.charCodeAt() + j);
                break;
            }
        }
    }
    return rec.join('');
};