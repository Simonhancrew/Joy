var exclusiveTime = function (n, logs) {
    let [ans, stk] = [new Array(n).fill(0), []];
    let last = 0;
    for (const log of logs) {
        const idx = parseInt(log.substring(0, log.indexOf(':')));
        const type = log.substring(log.indexOf(':') + 1, log.lastIndexOf(':'));
        const ts = parseInt(log.substring(log.lastIndexOf(':') + 1));
        if (type == "start") {
            if (stk.length) ans[stk[stk.length - 1]] += ts - last;
            stk.push(idx);
            last = ts;
        } else {
            ans[stk[stk.length - 1]] += ts - last + 1;
            last = ts + 1;
            stk.pop();
        }
    }
    return ans;
};