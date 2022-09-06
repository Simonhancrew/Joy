var uniqueLetterString = function(s) {
    const n = s.length;
    let [l,r,last] = [new Array(n).fill(0),new Array(n).fill(0),new Array(26).fill(-1)];
    for(let i = 0;i < n;i++) {
        l[i] = last[s[i].charCodeAt() - 'A'.charCodeAt()];
        last[s[i].charCodeAt() - 'A'.charCodeAt()] = i;
    }
    last.fill(n);
    for(let i = n - 1;i >= 0;i--) {
        r[i] = last[s[i].charCodeAt() - 'A'.charCodeAt()];
        last[s[i].charCodeAt() - 'A'.charCodeAt()] = i;
    }
    let ans = 0;
    for(let i = 0;i < n;i++) {
        ans += (i - l[i]) * (r[i] - i);
    }
    return ans;
};
