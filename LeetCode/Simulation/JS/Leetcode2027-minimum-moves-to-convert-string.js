var minimumMoves = function(s) {
    let [ans, n] = [0, s.length];
    for(let i = 0;i < n;i++) {
        if (s[i] == 'O') continue;
        i += 2;
        ans++;
    }
    return ans;
};
