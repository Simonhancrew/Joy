var numberOfLines = function (widths, s) {
    let [line, cnt] = [1, 0];
    for (const x of s) {
        let t = widths[x.charCodeAt(0) - 'a'.charCodeAt(0)];
        cnt += t;
        if (cnt > 100) {
            cnt = t;
            line++;
        }
    }
    return [line, cnt];
};  