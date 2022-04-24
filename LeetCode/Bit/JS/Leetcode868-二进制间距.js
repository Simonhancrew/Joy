var binaryGap = function (n) {
    let [res, cur, pre] = [0, 0, -1];
    while (n) {
        if (n & 1) {
            if (pre != -1) {
                res = Math.max(res, cur - pre);
            }
            pre = cur;
        }

        n >>= 1;
        cur++;
    }
    return res;
};