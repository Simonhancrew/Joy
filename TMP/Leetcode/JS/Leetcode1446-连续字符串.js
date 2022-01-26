var maxPower = function(s) {
    let res = 0;
    for(let i = 0,j = 0;i < s.length;i++){
        while(j < s.length && s[i] == s[j]) j++;
        res = Math.max(res,j - i);
        i = j - 1;
    }
    return res;
};