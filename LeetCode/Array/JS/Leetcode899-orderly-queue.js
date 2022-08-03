var orderlyQueue = function (s, k) {
    if (k == 1) {
        let res = s;
        for (let i = 0; i < s.length; i++) {
            s = s.substr(1) + s[0];
            if (res > s) {
                res = s;
            }
        }
        return res;
    }
    s = [...s];
    s.sort((a, b) => a.charCodeAt() - b.charCodeAt());
    return s.join('');
};