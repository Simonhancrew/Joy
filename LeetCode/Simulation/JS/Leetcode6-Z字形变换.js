var convert = function(s, numRows) {
    if(numRows == 1) return s;
    const res = []
    for(let i = 0;i < numRows;i++){
        if(i == 0 || i == numRows - 1){
            for(let j = i;j < s.length;j += 2 * numRows - 2) res.push(s[j]);
        }else{
            for(let j = i,k = 2 * numRows - 2 - i;j < s.length || k < s.length;j += 2 * numRows - 2,k += 2 * numRows - 2) {
                if(j < s.length) res.push(s[j]);
                if(k < s.length) res.push(s[k]);
            }
        }
    }
    return res.join('');
};