var removePalindromeSub = function(s) {
    for(let i = 0;i < s.length;i++) {
        if(s[i] != s[s.length - i - 1]) return 2;
    }
    return 1;
};