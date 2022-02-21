var pushDominoes = function(dominoes) {
    dominoes = "L" + dominoes + "R";
    const s = [...dominoes],n = s.length;
    const l = new Array(n).fill(0),r = new Array(n).fill(0);
    for(let i = 0,j = 0;i < n;i++) {
        if(s[i] != '.') j = i;
        l[i] = j;
    }
    for(let i = n - 1;i >= 0;i--) {
        if(s[i] != '.') j = i;
        r[i] = j;
    }
    for(let i = 0;i < n;i++) {
        const lhs = s[l[i]],rhs = s[r[i]];
        if(lhs == 'L' && rhs == 'L') s[i] = 'L';
        else if(lhs == 'L' && rhs == 'R') s[i] = '.';
        else if(lhs == 'R' && rhs == 'R') s[i] = 'R';
        else{
            if(i - l[i] < r[i] - i) s[i] = 'R';
            else if(i - l[i] > r[i] - i) s[i] = 'L';
            else s[i] = '.';
        } 
    }
    return s.slice(1,n - 1).join('');
};