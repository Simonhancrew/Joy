var findAndReplacePattern = function (words, pattern) {
    let [n, ans] = [pattern.length, []];
    for (const s of words) {
        if (s.length != n) continue;
        let [mp, vis] = [new Array(26).fill(-1), new Array(26).fill(0)];
        let ok = true;
        for (let i = 0; i < n; i++) {
            let [l, r] = [s[i].charCodeAt() - 'a'.charCodeAt(), pattern[i].charCodeAt() - 'a'.charCodeAt()];
            if (mp[l] == -1 && !vis[r]) {
                mp[l] = r;
                vis[r] = 1;
            } else if (mp[l] != r) {
                ok = false;
                break;
            }
        }
        if (ok) ans.push(s);
    }
    return ans;
};  