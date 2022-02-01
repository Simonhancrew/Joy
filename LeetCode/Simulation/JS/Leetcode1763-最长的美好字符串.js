var longestNiceSubstring = function(s) {
    n = s.length;
    let start = 0,len = 0;
    for(let l = 0;l < n;l++) {
        let a = 0,b = 0;
        for(let r = l;r < n;r++) {
            if(s[r] >= 'a' && s[r] <= 'z') a |= 1 << (s[r].codePointAt(0) - 'a'.codePointAt(0));
            else b |= 1 << (s[r].codePointAt(0) - 'A'.codePointAt(0));
            if(a == b && r - l + 1 > len) {
                len = r - l + 1;
                start = l;
            }
        }
    }
    return s.substr(start,len);
};